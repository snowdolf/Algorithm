#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> vec(n);
    for(int i = 0; i < n; i++)cin >> vec[i];

    vector<int> chk(d + 1, 0);

    int ans = 0, cnt = 0;

    for(int i = 0; i < k; i++){
        if(!chk[vec[i]])cnt++;
        chk[vec[i]]++;
    }
    ans = cnt + (chk[c] ? 0 : 1);

    for(int i = 0; i < n; i++){
        chk[vec[i]]--;
        if(!chk[vec[i]])cnt--;
        if(!chk[vec[(i + k) % n]])cnt++;
        chk[vec[(i + k) % n]]++;

        ans = max(ans, cnt + (chk[c] ? 0 : 1));
    }

    cout << ans;

    return 0;
}