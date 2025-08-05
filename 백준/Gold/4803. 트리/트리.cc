#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    for (int c = 1;; c++)
    {
        cin >> n >> m;
        if (n == 0) break;

        vector<int> adj[n + 1];

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> node(n + 1, -1);
        int tree = 0;

        for (int i = 1; i <= n; i++)
        {
            if (node[i] != -1) continue;

            bool isTree = true;
            queue<pair<int, int>> q;
            q.push({i, -1});
            node[i] = i;

            while (!q.empty())
            {
                pair<int, int> qf = q.front();
                q.pop();
                for (auto j : adj[qf.first])
                {
                    if (node[j] == -1)
                    {
                        q.push({j, qf.first});
                        node[j] = i;
                    }
                    else if (qf.second != j)
                    {
                        isTree = false;
                    }
                }
            }

            if (isTree) tree++;
        }

        cout << "Case " << c << ": ";
        if (tree == 0)
            cout << "No trees.\n";
        else if (tree == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << tree << " trees.\n";
    }

    return 0;
}