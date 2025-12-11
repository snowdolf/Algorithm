#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 1; i <= n; i++) dq.push_back(i);

    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        v.push_back(dq.front());
        dq.pop_front();
    }

    vector<int> ans(n);

    for (int i = 1; i <= n; i++) ans[v[i - 1] - 1] = i;

    for (auto x : ans) cout << x << " ";

    return 0;
}