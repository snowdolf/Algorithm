#include <iostream>

using namespace std;

int n, m, ans;
bool chk[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--){
        cin >> m;
        if(chk[m])ans++;
        else chk[m] = true;
    }

    cout << ans;

    return 0;
}