#include <iostream>

using namespace std;

int n, m, j, cur = 1, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> j;
    for(int i = 0; i < j; i++){
        int cnt;
        cin >> cnt;
        if(cnt < cur){
            ans += cur - cnt;
            cur = cnt;
        }
        else if(cur + m <= cnt){
            ans += cnt - cur - m + 1;
            cur = cnt - m + 1;
        }
    }

    cout << ans;

    return 0;
}