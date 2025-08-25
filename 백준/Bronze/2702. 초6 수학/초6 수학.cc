#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b;
    
    cin >> t;

    while(t--)
    {
        cin >> a >> b;
        int g = gcd(a, b);
        cout << a * b / g << " " << g << "\n";
    }

    return 0;
}