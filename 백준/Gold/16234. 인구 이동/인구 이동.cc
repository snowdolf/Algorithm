#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r;
    cin >> n >> l >> r;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

    int t = 0;
    while(true)
    {
        vector<vector<int>> v(n, vector<int>(n, 0));
        vector<int> sum(1, 0);
        vector<int> cnt(1, 0);

        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j]) continue;

                queue<pair<int, int>> q;

                q.push({i, j});
                v[i][j] = ++tmp;
                sum.push_back(a[i][j]);
                cnt.push_back(1);

                while(!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (v[nx][ny]) continue;
                        if (abs(a[nx][ny] - a[x][y]) < l || abs(a[nx][ny] - a[x][y]) > r) continue;

                        q.push({nx, ny});
                        v[nx][ny] = tmp;
                        sum[tmp] += a[nx][ny];
                        cnt[tmp]++;
                    }
                }
            }
        }

        if (tmp == n * n) break;
        t++;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp = v[i][j];
                a[i][j] = sum[tmp] / cnt[tmp];
            }
        }
    }

    cout << t;

    return 0;
}