#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, m, n, x, y, ans;

    cin >> t;
    while(t--){
        cin >> m >> n >> x >> y;
        y %= n;
        ans = -1;
        for(int i = 0; i < n; i++){
            int cnt = m * i + x;
            if(cnt % n == y){
                ans = cnt;
                break;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}