#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a = -1000000, b = 1000000, x;
        while (n--)
        {
            cin >> x;
            a = max(a, x);
            b = min(b, x);
        }

        cout << b << " " << a << "\n";
    }

    return 0;
}