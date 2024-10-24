#include <iostream>

using namespace std;

long long n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    if(n > m)n ^= m ^= n^= m;

    if(n == m)cout << "0\n";
    else cout << m - n - 1 << "\n";

    for(long long i = n + 1; i < m; i++)cout << i << " ";

    return 0;
}