#include <iostream>
#include <vector>

using namespace std;

int v, a, b, c, maxSum, maxVertex;

vector<pair<int, int>> edge[100005];

bool chk[100005];

void dfs(int x, int sum)
{
    if (sum > maxSum)
    {
        maxSum = sum;
        maxVertex = x;
    }

    chk[x] = true;

    for (auto i : edge[x])
        if (!chk[i.first])
            dfs(i.first, sum + i.second);

    chk[x] = false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v;
    for (int i = 1; i < v; i++)
    {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    for (int i = 1; i <= v; i++)
        chk[i] = false;
    dfs(1, 0);
    for (int i = 1; i <= v; i++)
        chk[i] = false;
    dfs(maxVertex, 0);

    cout << maxSum;

    return 0;
}
