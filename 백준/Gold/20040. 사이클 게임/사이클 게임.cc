#include <iostream>
#include <vector>

using namespace std;

int find(int x, vector<int> &root)
{
    if (root[x] == x) return x;
    return root[x] = find(root[x], root);
}

void unite(int x, int y, vector<int> &root, vector<int> &height)
{
    x = find(x, root);
    y = find(y, root);
    if (x == y) return;

    if (height[x] < height[y]) root[x] = y;
    else
    {
        root[y] = x;
        if (height[x] == height[y]) height[x]++;
    }
}

bool same(int x, int y, vector<int> &root)
{
    return find(x, root) == find(y, root);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans = 0;
    cin >> n >> m;

    vector<int> root(n), height(n, 1);
    for (int i = 0; i < n; i++) root[i] = i;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        if (same(a, b, root) && !ans) ans = i;
        unite(a, b, root, height);
    }

    cout << ans << '\n';

    return 0;
}