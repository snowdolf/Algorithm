#include <iostream>
#include <queue>

using namespace std;

int n, m, cp[605][605], ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char c;

bool chk[605][605];
pair<int, int> st;
queue<pair<int, int>> que;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == 'X')
                cp[i][j] = -1;
            if (c == 'I')
                st = {i, j};
            if (c == 'P')
                cp[i][j] = 1;
        }
    }

    que.push(st);
    chk[st.first][st.second] = true;
    while (!que.empty())
    {
        pair<int, int> qf = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> np = {qf.first + dx[i], qf.second + dy[i]};
            if (np.first < 0 || np.first >= n || np.second < 0 || np.second >= m)
                continue;
            if (cp[np.first][np.second] == -1)
                continue;
            if (chk[np.first][np.second])
                continue;

            if (cp[np.first][np.second] == 1)
                ans++;
            que.push(np);
            chk[np.first][np.second] = true;
        }
    }

    if (ans)
        cout << ans;
    else
        cout << "TT";

    return 0;
}