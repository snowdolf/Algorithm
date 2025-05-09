#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
int n, a, b, c = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 2; i <= n; i++){
        a = b;
        b = c;
        c = (a + b) % MOD;
    }

    if(!n)c = 0;
    cout << c;

    return 0;
}