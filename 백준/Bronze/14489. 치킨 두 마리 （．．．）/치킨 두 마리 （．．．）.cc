#include <iostream>

using namespace std;

int a, b, c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    if (a + b >= 2 * c)
        cout << a + b - 2 * c;
    else
        cout << a + b;

    return 0;
}