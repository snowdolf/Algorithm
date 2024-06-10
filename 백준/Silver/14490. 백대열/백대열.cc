#include <iostream>
#include <string>

using namespace std;

int n, m, g;

int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    n = stoi(str.substr(0, str.find(":")));
    m = stoi(str.substr(str.find(":") + 1, str.length()));

    g = gcd(n, m);

    n /= g;
    m /= g;

    cout << n << ":" << m;

    return 0;
}