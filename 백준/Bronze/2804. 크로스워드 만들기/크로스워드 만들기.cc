#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    int x, y;
    for (x = 0; x < a.size(); x++)
    {
        for (y = 0; y < b.size(); y++)
        {
            if (a[x] == b[y])
            {
                goto found;
            }
        }
    }
    found:;

    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (j == x) cout << b[i];
            else if (i == y) cout << a[j];
            else cout << '.';
        }
        cout << '\n';
    }

    return 0;
}