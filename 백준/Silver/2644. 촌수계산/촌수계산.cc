#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, a, b, m, x, y, ans = -1;
vector<int> v[105];
queue<int> q;
int chk[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> m;
    while (m--)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    q.push(a);
    chk[a] = 1;
    while (!q.empty())
    {
        int qf = q.front();
        q.pop();

        if (qf == b)
        {
            ans = chk[qf] - 1;
            break;
        }

        for (auto i : v[qf])
        {
            if (chk[i])
                continue;
            q.push(i);
            chk[i] = chk[qf] + 1;
        }
    }

    cout << ans;

    return 0;
}
