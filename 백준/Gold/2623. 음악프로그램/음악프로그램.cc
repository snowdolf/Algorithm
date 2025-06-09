#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void dfs(int node, set<int> adj[], vector<bool> &visited, vector<int> &ord){
    visited[node] = true;
    for(int i : adj[node]){
        if(!visited[i]){
            dfs(i, adj, visited, ord);
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

    set<int> adj[n + 1];
    while(m--){
        int p, q, r;
        cin >> p >> q;
        while(--p){
            cin >> r;
            adj[q].insert(r);
            q = r;
        }
    }

    vector<bool> visited(n + 1, false);
    vector<int> ord;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, adj, visited, ord);
        }
    }
    reverse(ord.begin(), ord.end());

    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            if(adj[ord[j]].find(ord[i]) != adj[ord[j]].end()){
                cout << "0\n";
                return 0;
            }
        }
    }

    for(int i = 0; i < ord.size(); i++){
        cout << ord[i] << "\n";
    }

    return 0;
}