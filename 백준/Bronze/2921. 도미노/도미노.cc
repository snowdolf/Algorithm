#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = i; j <= n; j++){
            ans += i + j;
        }
    }

    cout << ans;

    return 0;
}