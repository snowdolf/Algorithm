#include <iostream>

using namespace std;

int n, s[200010], f[10], ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)cin >> s[i];

    int l = 0, r = 0, cnt = 1, sum = 1;
    f[s[l]]++;

    while(l <= r && r < n){
        if(cnt <= 2 && ans < sum)ans = sum;

        if(cnt <= 2){
            r++;
            if(!f[s[r]])cnt++;
            f[s[r]]++;
            sum++;
        }
        else{
            l++;
            f[s[l - 1]]--;
            if(!f[s[l - 1]])cnt--;
            sum--;
        }
    }

    cout << ans;

    return 0;
}