#include <iostream>
#include <algorithm>

using namespace std;

int n, a[1010], ans, cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];

    for(int i = 0; i < n; i++){
        if(cnt % 3 == 0 && a[i] == 0){
            cnt++;
        }
        else if(cnt % 3 == 1 && a[i] == 1){
            cnt++;
        }
        else if(cnt % 3 == 2 && a[i] == 2){
            cnt++;
        }
        else{
            ans = max(ans, cnt);
        }
    }

    ans = max(ans, cnt);
    cout << ans;

    return 0;
}