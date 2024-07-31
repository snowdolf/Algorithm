#include <iostream>

using namespace std;

int n, a, b;
string str[105];

void f(int &count, bool isRow)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            int x = isRow ? i : j;
            int y = isRow ? j : i;
            if (str[x][y] != '.' || str[x + (isRow ? 0 : 1)][y + (isRow ? 1 : 0)] != '.')
                continue;
            int k = 2;
            while (j + k < n && str[x + (isRow ? 0 : k)][y + (isRow ? k : 0)] == '.')
            {
                k++;
            }
            j += k;
            count++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    f(a, true);
    f(b, false);

    cout << a << " " << b;

    return 0;
}