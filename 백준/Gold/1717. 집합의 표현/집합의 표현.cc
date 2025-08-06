#include <iostream>
#include <vector>

using namespace std;

vector<int> par(1000001), ran(1000001, 0);

int find(int x)
{
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (ran[x] < ran[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if (ran[x] == ran[y]) ran[x]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) par[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 0)
        {
            unite(a, b);
        }
        else
        {
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}