#include <iostream>
#include <vector>

using namespace std;

vector<int> par(201), ran(201, 0);

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

    if (ran[x] < ran[y]) par[x] = y;
    else
    {
        par[y] = x;
        if (ran[x] == ran[y]) ran[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
    {
        int x;
        cin >> x;
        if (x == 1) unite(i, j);
    }

    bool isPossible = true;
    vector<int> plan(m);
    for (auto &x : plan) cin >> x;

    for (int i = 0; i < m - 1; i++)
    {
        if (!same(plan[i], plan[i + 1]))
        {
            isPossible = false;
            break;
        }
    }

    cout << (isPossible ? "YES" : "NO") << "\n";

    return 0;
}