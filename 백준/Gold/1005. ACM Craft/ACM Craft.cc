#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int node, vector<bool> &visited, vector<int> &ord, const vector<int> adj[]) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, visited, ord, adj);
        }
    }
    ord.push_back(node);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<int> d(n + 1);
        for(int i = 1; i <= n; i++)cin >> d[i];

        vector<int> adj[n + 1], rev_adj[n + 1];
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            rev_adj[y].push_back(x);
        }

        int w;
        cin >> w;

        vector<bool> visited(n + 1, false);
        vector<int> ord;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                dfs(i, visited, ord, adj);
            }
        }
        reverse(ord.begin(), ord.end());

        vector<int> dp(n + 1, 0);
        for(int node : ord){
            dp[node] = d[node];
            for(int neighbor : rev_adj[node]){
                dp[node] = max(dp[node], dp[neighbor] + d[node]);
            }
        }

        cout << dp[w] << "\n";
    }

    return 0;
}