#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    double a, b;
    cin >> a;

    cout.precision(2);
    cout << fixed;

    while (1)
    {
        cin >> b;
        if ((int)b == 999) break;
        cout << b - a << "\n";
        a = b;
    }

    return 0;
} 