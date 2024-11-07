#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x, ans, cnt, sum;
vector<int> vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    vec.resize(n);
    for(int i = 0; i < n; i++)cin >> vec[i];

    for(int i = 0; i < x; i++)sum += vec[i];
    ans = sum;
    if(ans)cnt = 1;

    for(int i = x; i < n; i++){
        sum += vec[i] - vec[i - x];
        if(ans == sum)cnt++;
        else if(ans < sum){
            ans = sum;
            cnt = 1;
        }
    }

    if(ans)cout << ans << "\n" << cnt;
    else cout << "SAD";

    return 0;
}