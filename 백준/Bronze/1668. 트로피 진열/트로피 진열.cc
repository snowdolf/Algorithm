#include <iostream>

using namespace std;

int n, t[100], ans, tmp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)cin >> t[i];

    for(int i = 0; i < n; i++){
        if(tmp < t[i]){
            tmp = t[i];
            ans++;
        }
    }
    cout << ans << "\n";

    ans = tmp = 0;
    for(int i = n - 1; i >= 0; i--){
        if(tmp < t[i]){
            tmp = t[i];
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}