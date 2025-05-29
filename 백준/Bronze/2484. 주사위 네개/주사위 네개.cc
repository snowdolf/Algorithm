#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;

    while(n--){
        vector<int> v(4);
        cin >> v[0] >> v[1] >> v[2] >> v[3];
        sort(v.begin(), v.end());

        int tmp = 0;

        if(v[0] == v[3])tmp = 50000 + v[0] * 5000;
        else if(v[0] == v[2] || v[1] == v[3])tmp = 10000 + v[1] * 1000;
        else if(v[0] == v[1] && v[2] == v[3])tmp = 2000 + v[0] * 500 + v[2] * 500;
        else if(v[0] == v[1])tmp = 1000 + v[0] * 100;
        else if(v[1] == v[2])tmp = 1000 + v[1] * 100;
        else if(v[2] == v[3])tmp = 1000 + v[2] * 100;
        else tmp = v[3] * 100;

        ans = max(ans, tmp);
    }

    cout << ans;

    return 0;
}