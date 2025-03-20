#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, t[10001], inDegree[10001], start[10001], finish[10001], ans;
vector<int> task[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        int cnt;
        cin >> cnt;
        while (cnt--)
        {
            int x;
            cin >> x;
            task[x].push_back(i); // x -> i
            inDegree[i]++;
        }
    }

    // 위상정렬
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        finish[cur] = start[cur] + t[cur];
        ans = max(ans, finish[cur]);

        for (int next : task[cur])
        {
            start[next] = max(start[next], finish[cur]);
            if (--inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    cout << ans;

    return 0;
}