#include <iostream>

using namespace std;

int n, m[2], a = 1, b = 1, res;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m[0];
    while (--n)
    {
        cin >> m[1];
        if (m[0] < m[1])
        {
            a++;
            res = res > b ? res : b;
            b = 1;
        }
        if (m[0] > m[1])
        {
            b++;
            res = res > a ? res : a;
            a = 1;
        }
        if (m[0] == m[1])
        {
            a++;
            b++;
        }
        m[0] = m[1];
    }
    res = res > a ? res : a;
    res = res > b ? res : b;

    cout << res;

    return 0;
}