#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout.precision(2);
    cout << fixed;

    while (n--)
    {
        double d;
        cin >> d;

        cout << "$" << round(d * 0.8 * 100) / 100 << "\n";
    }

    return 0;
}