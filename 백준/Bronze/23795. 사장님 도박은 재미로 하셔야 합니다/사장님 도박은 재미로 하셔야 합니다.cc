#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0, n;
    while(cin >> n && n != -1){
        ans += n;
    }
    cout << ans;

    return 0;
}