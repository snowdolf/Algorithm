#include <iostream>
#include <vector>

using namespace std;

int calculateSize(int current, int parent, vector<int> node[], vector<int> &size){
    int totalSize = 1;

    for(auto child : node[current]){
        if(child != parent){
            totalSize += calculateSize(child, current, node, size);
        }
    }

    return size[current] = totalSize;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, q;
    cin >> n >> r >> q;

    vector<int> node[n + 1];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    vector<int> size(n + 1, 0);
    calculateSize(r, -1, node, size);

    for(int i = 0; i < q; i++){
        int u;
        cin >> u;
        cout << size[u] <<"\n";
    }

    return 0;
}