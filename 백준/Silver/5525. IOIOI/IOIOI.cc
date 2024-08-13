#include <iostream>

using namespace std;

int n, m, ans, kmp[2000010];
string a, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a;

    b = "I";
    for(int i = 0; i < n; i++)b += "OI";

    n = 2 * n + 1;

    for(int i = 1, j = 0; i < n; i++){
        while(j && b[i] != b[j])j = kmp[j - 1];
        if(b[i] == b[j])kmp[i] = ++j;
    }

    for(int i = 0, j = 0; i < m; i++){
        while(j && a[i] != b[j])j = kmp[j - 1];
        if(a[i] == b[j])j++;
        if(j == n){
            ans++;
            j = kmp[j - 1];
        }
    }

    cout << ans;

    return 0;
}