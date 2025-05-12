#include <iostream>

using namespace std;

int t, n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << 2 * m - n << " " << n - m << "\n";
    }

    return 0;
}