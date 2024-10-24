#include <iostream>

using namespace std;

int n, cnt, l, r, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        cin >> cnt;
        if(!l){
            l = cnt;
            r = cnt;
        }
        else if(r < cnt){
            r = cnt;
        }
        else{
            if(ans < r - l)ans = r - l;
            l = cnt;
            r = cnt;
        }
    }

    if(ans < r - l)ans = r - l;

    cout << ans;

    return 0;
}