#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[22][22], ans, cnt;

void cmpArr()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, arr[i][j]);
    return;
}

void moveUp()
{
    for (int j = 0; j < n; j++)
    {
        int s = 0, l = -1, r = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j])
            {
                if (l < 0)
                    l = i;
                else if (r < 0)
                {
                    r = i;
                    if (arr[l][j] == arr[r][j])
                    {
                        cnt = arr[l][j] + arr[r][j];
                        arr[l][j] = arr[r][j] = 0;
                        arr[s++][j] = cnt;
                        l = r = -1;
                    }
                    else
                    {
                        cnt = arr[l][j];
                        arr[l][j] = 0;
                        arr[s++][j] = cnt;
                        l = r;
                        r = -1;
                    }
                }
            }
        }
        if (l >= 0)
        {
            cnt = arr[l][j];
            arr[l][j] = 0;
            arr[s++][j] = cnt;
        }
    }
    return;
}

void moveDown()
{
    for (int j = 0; j < n; j++)
    {
        int s = n - 1, l = -1, r = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i][j])
            {
                if (l < 0)
                    l = i;
                else if (r < 0)
                {
                    r = i;
                    if (arr[l][j] == arr[r][j])
                    {
                        cnt = arr[l][j] + arr[r][j];
                        arr[l][j] = arr[r][j] = 0;
                        arr[s--][j] = cnt;
                        l = r = -1;
                    }
                    else
                    {
                        cnt = arr[l][j];
                        arr[l][j] = 0;
                        arr[s--][j] = cnt;
                        l = r;
                        r = -1;
                    }
                }
            }
        }
        if (l >= 0)
        {
            cnt = arr[l][j];
            arr[l][j] = 0;
            arr[s--][j] = cnt;
        }
    }
    return;
}

void moveLeft()
{
    for (int i = 0; i < n; i++)
    {
        int s = 0, l = -1, r = -1;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j])
            {
                if (l < 0)
                    l = j;
                else if (r < 0)
                {
                    r = j;
                    if (arr[i][l] == arr[i][r])
                    {
                        cnt = arr[i][l] + arr[i][r];
                        arr[i][l] = arr[i][r] = 0;
                        arr[i][s++] = cnt;
                        l = r = -1;
                    }
                    else
                    {
                        cnt = arr[i][l];
                        arr[i][l] = 0;
                        arr[i][s++] = cnt;
                        l = r;
                        r = -1;
                    }
                }
            }
        }
        if (l >= 0)
        {
            cnt = arr[i][l];
            arr[i][l] = 0;
            arr[i][s++] = cnt;
        }
    }
    return;
}

void moveRight()
{
    for (int i = 0; i < n; i++)
    {
        int s = n - 1, l = -1, r = -1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (arr[i][j])
            {
                if (l < 0)
                    l = j;
                else if (r < 0)
                {
                    r = j;
                    if (arr[i][l] == arr[i][r])
                    {
                        cnt = arr[i][l] + arr[i][r];
                        arr[i][l] = arr[i][r] = 0;
                        arr[i][s--] = cnt;
                        l = r = -1;
                    }
                    else
                    {
                        cnt = arr[i][l];
                        arr[i][l] = 0;
                        arr[i][s--] = cnt;
                        l = r;
                        r = -1;
                    }
                }
            }
        }
        if (l >= 0)
        {
            cnt = arr[i][l];
            arr[i][l] = 0;
            arr[i][s--] = cnt;
        }
    }
    return;
}

void f(int curMove)
{
    cmpArr();
    if (curMove == 5)
        return;

    int brr[22][22];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            brr[i][j] = arr[i][j];

    moveUp();
    f(curMove + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = brr[i][j];

    moveDown();
    f(curMove + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = brr[i][j];

    moveLeft();
    f(curMove + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = brr[i][j];

    moveRight();
    f(curMove + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = brr[i][j];

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    f(0);

    cout << ans;

    return 0;
}