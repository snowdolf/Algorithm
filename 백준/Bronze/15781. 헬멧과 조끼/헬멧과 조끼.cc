#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a = 0;
    while (n--)
    {
        int x;
        cin >> x;
        a = max(a, x);
    }

    int b = 0;
    while (m--)
    {
        int x;
        cin >> x;
        b = max(b, x);
    }

    cout << a + b << "\n";

    return 0;
}