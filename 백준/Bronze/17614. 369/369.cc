#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int x = i;
        while(x){
            int cnt = x % 10;
            if(cnt && !(cnt % 3))ans++;
            x /= 10;
        }
    }

    cout << ans;

    return 0;
}