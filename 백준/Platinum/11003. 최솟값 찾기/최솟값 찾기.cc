#include <iostream>
#include <deque>

using namespace std;

int n, l, a;
deque<pair<int, int>> dq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (!dq.empty() && dq.front().second < i - l + 1)
        {
            dq.pop_front();
        }
        while (!dq.empty() && dq.back().first > a)
        {
            dq.pop_back();
        }
        dq.push_back({a, i});
        cout << dq.front().first << " ";
    }

    return 0;
}