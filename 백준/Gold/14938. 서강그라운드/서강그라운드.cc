#include <iostream>
#include <algorithm>

using namespace std;

int n, m, r, t[105], d[105][105], INF = 10000;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
        for(int j = 1; j <= n; j++){
            if(i != j){
                d[i][j] = INF;
            }
        }
    }

    for(int i = 0; i < r; i++){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= n; j++){
            if(d[i][j] <= m){
                sum += t[j];
            }
        }
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}