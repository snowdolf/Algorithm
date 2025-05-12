#include <iostream>

using namespace std;

long long n, f[55], c, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> f[i];
    }

    cin >> c;

    for(int i = 0; i < n; i++){
        ans += (f[i] / c + (f[i] % c ? 1 : 0)) * c;
    }

    cout << ans;

    return 0;
}