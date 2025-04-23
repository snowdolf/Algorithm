#include <iostream>

using namespace std;

long long n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    if(n > m)swap(n, m);

    if(m == 1)cout << 0;
    else if(m % 2 == 0)cout << n * (m / 2);
    else cout << n * (m / 2) + n / 2;

    return 0;
}