#include <iostream>
#include <queue>

using namespace std;

int n, cnt, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> cnt;
        pq.push(cnt);
    }

    while (pq.size() > 1)
    {
        cnt = pq.top();
        pq.pop();
        cnt += pq.top();
        pq.pop();
        ans += cnt;
        pq.push(cnt);
    }

    cout << ans;

    return 0;
}