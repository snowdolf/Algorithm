#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int a, b, x, w = 0;
        cin >> a >> b >> x;
        cout << a * (x - 1) + b << "\n";
    }

    return 0;
}