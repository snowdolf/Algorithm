#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tc, n, t[505], m, a, b;
bool adj[505][505], visited[505];
vector<int> ans;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = false;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }

    ans.clear();
}

void makeGraph()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            adj[t[i]][t[j]] = true;
        }
    }

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        swap(adj[a][b], adj[b][a]);
    }
}

void dfs(int node)
{
    visited[node] = true;
    for (int i = 1; i <= n; i++)
    {
        if (adj[node][i] && !visited[i])
        {
            dfs(i);
        }
    }
    ans.push_back(node);
}

void topologicalSort()
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (adj[ans[j]][ans[i]])
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--)
    {
        init();
        makeGraph();
        topologicalSort();
    }

    return 0;
}