#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans;
    string a, b, c;

    cin >> n >> m >> b;

    a = "I";
    for(int i = 0; i < n; i++)a += "OI";

    n = 2 * n + 1;

    for(int i = 0; i <= m - n; i++){
        c = b.substr(i, n);
        if(a == c)ans++;
    }

    cout << ans;

    return 0;
}