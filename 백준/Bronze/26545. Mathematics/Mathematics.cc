#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    while(n--){
        int tmp;
        cin >> tmp;
        ans += tmp;
    }

    cout << ans;

    return 0;
}