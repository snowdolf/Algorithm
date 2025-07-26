#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, a, b, c;
int d[105][105], past[105][105];
int INF = 1e9;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = INF, past[i][j] = -1;
    for (int i = 0; i < n; i++) d[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        d[a - 1][b - 1] = min(d[a - 1][b - 1], c);
        past[a - 1][b - 1] = a - 1;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    past[i][j] = past[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] >= INF) cout << "0 ";
            else cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (past[i][j] == -1)
            {
                cout << "0\n";
                continue;
            }

            vector<int> path;
            int s = i, e = j;
            while (e != -1)
            {
                path.push_back(e + 1);
                e = past[s][e];
            }
            reverse(path.begin(), path.end());

            cout << path.size() << " ";
            for (auto x : path) cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}