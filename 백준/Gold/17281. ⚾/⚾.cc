#include <iostream>
#include <algorithm>

using namespace std;

int n, act[55][15], ans;
int ord[15];
bool chk[15];

int g(int inning, int idx, int sum)
{
    if (inning > n)
        return sum;

    int one = 0, two = 0, thr = 0, out = 0;

    while (out < 3)
    {
        switch (act[inning][ord[idx]])
        {
        case 1:
            sum = sum + thr;
            thr = two;
            two = one;
            one = 1;
            break;
        case 2:
            sum = sum + thr + two;
            thr = one;
            two = 1;
            one = 0;
            break;
        case 3:
            sum = sum + thr + two + one;
            thr = 1;
            two = 0;
            one = 0;
            break;
        case 4:
            sum = sum + thr + two + one + 1;
            thr = 0;
            two = 0;
            one = 0;
            break;
        case 0:
            out++;
            break;
        default:
            break;
        }

        idx++;
        if (idx > 9)
            idx = 1;
    }

    return g(inning + 1, idx, sum);
}

void f(int x)
{
    if (x > 9)
    {
        int cnt = g(1, 1, 0);
        ans = max(ans, cnt);
        return;
    }
    if (x == 4)
    {
        f(x + 1);
        return;
    }
    for (int i = 2; i <= 9; i++)
    {
        if (chk[i])
            continue;
        ord[x] = i;
        chk[i] = true;
        f(x + 1);
        chk[i] = false;
        ord[x] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 9; j++)
            cin >> act[i][j];

    // 4번 타자 = 1번 선수
    ord[4] = 1;
    chk[1] = true;

    f(1);

    cout << ans;

    return 0;
}