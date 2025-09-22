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

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int ans = 0, tmp, cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur == 0)
        {
            tmp = 0;
            cur = v[i];
        }
        else if (cur > v[i])
        {
            tmp++;
        }
        else
        {
            ans = max(ans, tmp);
            tmp = 0;
            cur = v[i];
        }
    }
    ans = max(ans, tmp);

    cout << ans;

    return 0;
}