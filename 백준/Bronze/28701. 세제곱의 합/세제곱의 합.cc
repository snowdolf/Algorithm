#include <iostream>

using namespace std;

int n, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ans = n * (n + 1) / 2;
    cout << ans << "\n";
    ans *= ans;
    cout << ans << "\n" << ans;

    return 0;
}