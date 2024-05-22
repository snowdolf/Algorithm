#include <iostream>

using namespace std;

int n, maxans[15], minans[15], cnt[15];
char vs[15];
bool chk[15];

bool cmp(int arr[], int brr[])
{
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] < brr[i])
            return true;
        else if (arr[i] > brr[i])
            return false;
        else
            continue;
    }
    return true;
}

void f(int x)
{
    if (x == n + 1)
    {
        if (cmp(maxans, cnt))
            for (int i = 0; i <= n; i++)
                maxans[i] = cnt[i];
        if (cmp(cnt, minans))
            for (int i = 0; i <= n; i++)
                minans[i] = cnt[i];
    }

    for (int i = 0; i < 10; i++)
    {
        if (chk[i])
            continue;
        if (x && vs[x - 1] == '<' && cnt[x - 1] >= i)
            continue;
        if (x && vs[x - 1] == '>' && cnt[x - 1] <= i)
            continue;
        cnt[x] = i;
        chk[i] = true;
        f(x + 1);
        chk[i] = false;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> vs[i];
        maxans[i] = 0;
        minans[i] = 9;
    }
    maxans[n] = 0;
    minans[n] = 9;

    f(0);

    for (int i = 0; i <= n; i++)
        cout << maxans[i];
    cout << "\n";
    for (int i = 0; i <= n; i++)
        cout << minans[i];

    return 0;
}