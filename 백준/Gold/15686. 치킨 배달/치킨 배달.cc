#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt, sum, ans = 10000;
vector<pair<int, int>> home, chicken;
int arr[15];
bool chk[15];

int h(pair<int, int> x, pair<int, int> y)
{
    int a = x.first - y.first;
    a = a > 0 ? a : -a;
    int b = x.second - y.second;
    b = b > 0 ? b : -b;

    return a + b;
}

void g()
{
    sum = 0;
    for (auto i : home)
    {
        cnt = 1000;
        for (int j = 0; j < m; j++)
        {
            cnt = cnt > h(i, chicken[arr[j]]) ? h(i, chicken[arr[j]]) : cnt;
        }
        sum += cnt;
    }
    ans = ans > sum ? sum : ans;
}

void f(int idx)
{
    if (idx == m)
    {
        g();
    }
    else
    {
        for (int i = 0; i < chicken.size(); i++)
        {
            if (chk[i])
                continue;
            if (idx && arr[idx - 1] >= i)
                continue;
            arr[idx] = i;
            chk[i] = true;
            f(idx + 1);
            chk[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cnt;
            if (cnt == 1)
            {
                home.push_back({i, j});
            }
            if (cnt == 2)
            {
                chicken.push_back({i, j});
            }
        }
    }

    f(0);

    cout << ans;

    return 0;
}