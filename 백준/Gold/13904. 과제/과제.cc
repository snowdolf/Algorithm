#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> scores(n);
    for (auto &score : scores) cin >> score.first >> score.second;

    sort(scores.begin(), scores.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto &score : scores)
    {
        pq.push(score.second);
        while (pq.size() > score.first) pq.pop();
    }

    int ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << "\n";

    return 0;
}