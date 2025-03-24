#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int w, h, n, ans;
vector<int> x, y;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a) x.push_back(b);
        else y.push_back(b);
    }

    x.push_back(0);
    x.push_back(w);
    y.push_back(0);
    y.push_back(h);

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for(int i = 1; i < x.size(); i++){
        for(int j = 1; j < y.size(); j++){
            ans = max(ans, (x[i] - x[i - 1]) * (y[j] - y[j - 1]));
        }
    }

    cout << ans;

    return 0;
}