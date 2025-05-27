#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int node, vector<int> &ord, vector<bool> &visited, const vector<int> adj[]){
    visited[node] = true;
    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(i, ord, visited, adj);
        }
    }
    ord.push_back(node);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> visited(n + 1, false);
    vector<int> ord;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, ord, visited, adj);
        }
    }
    reverse(ord.begin(), ord.end());
    
    for(auto i : ord)cout << i << " ";

    return 0;
}