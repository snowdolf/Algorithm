#include <iostream>

using namespace std;

int n, s, m, vol[55];
bool chk[55][1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> m;
    for(int i = 1; i <= n; i++)cin >> vol[i];

    chk[0][s] = true;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(chk[i - 1][j]){
                if((j + vol[i]) <= m){
                    chk[i][j + vol[i]] = true;
                }
                if((j - vol[i]) >= 0){
                    chk[i][j - vol[i]] = true;
                }
            }
        }
    }

    int ans = -1;
    for(int i = m; i >= 0; i--){
        if(chk[n][i]){
            ans = i;
            break;
        }
    }

    cout << ans;

    return 0;
}