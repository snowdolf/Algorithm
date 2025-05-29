#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = i; i * j <= n; j++){
            ans++;
        }
    }

    cout << ans;

    return 0;
}