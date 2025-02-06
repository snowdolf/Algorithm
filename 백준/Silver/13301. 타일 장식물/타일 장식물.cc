#include <iostream>

using namespace std;

long long n, a = 1, b = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(--n){
        a ^= b ^= a^= b;
        a += b;
    }

    cout << 4 * a + 2 * b;

    return 0;
}