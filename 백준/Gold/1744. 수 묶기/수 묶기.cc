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
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        
        if (x == 1) ans++;
        else if (x > 1) pos.push_back(x);
        else neg.push_back(x);
    }

    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());

    for (int i = 0; i < pos.size(); i += 2)
    {
        if (i + 1 < pos.size()) ans += pos[i] * pos[i + 1];
        else ans += pos[i];
    }
    for (int i = 0; i < neg.size(); i += 2)
    {
        if (i + 1 < neg.size()) ans += neg[i] * neg[i + 1];
        else ans += neg[i];
    }

    cout << ans;

    return 0;
}