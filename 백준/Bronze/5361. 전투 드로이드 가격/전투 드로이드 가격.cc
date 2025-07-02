#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;

        int sum = 0;

        sum += 35034 * a;
        sum += 23090 * b;
        sum += 19055 * c;
        sum += 12530 * d;
        sum += 18090 * e;

        cout << '$' << sum / 100 << '.';
        cout << setw(2) << setfill('0') << sum % 100 << '\n';
    }

    return 0;
}