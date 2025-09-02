#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w, h, l;
    cin >> n >> w >> h >> l;

    int ans  = (w / l) * (h / l);
    ans = min(ans, n);

    cout << ans;

    return 0;
}