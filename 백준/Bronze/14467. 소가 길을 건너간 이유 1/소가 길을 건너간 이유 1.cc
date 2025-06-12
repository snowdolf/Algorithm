#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;

    vector<int> c(n + 1, -1);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(c[x] != -1 && c[x] != y)ans++;
        c[x] = y;
    }

    cout << ans;

    return 0;
}