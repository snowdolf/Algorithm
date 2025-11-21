#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> pp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int problem = 1; ; problem++)
    {
        int n;
        cin >> n;

        if (n == 0) break;

        vector<vector<int>> rupee(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> rupee[i][j];
            }
        }

        vector<vector<int>> d(n, vector<int>(n, 100000));
        d[0][0] = rupee[0][0];

        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({d[0][0], {0, 0}});

        while (!pq.empty())
        {
            auto [c, u] = pq.top();
            pq.pop();

            if (d[u.first][u.second] < c) continue;

            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, -1, 1};

            for (int dir = 0; dir < 4; dir++)
            {
                pair<int, int> v = {u.first + dx[dir], u.second + dy[dir]};

                if (v.first < 0 || v.first == n || v.second < 0 || v.second == n) continue;

                if (d[v.first][v.second] > d[u.first][u.second] + rupee[v.first][v.second])
                {
                    d[v.first][v.second] = d[u.first][u.second] + rupee[v.first][v.second];
                    pq.push({d[v.first][v.second], {v.first, v.second}});
                }
            }
        }

        cout << "Problem " << problem << ": " << d[n - 1][n - 1] << "\n";
    }

    return 0;
}