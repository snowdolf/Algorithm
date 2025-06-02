#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll n, m, d;

vector<vector<ll>> matrixMul(vector<vector<ll>> x, vector<vector<ll>> y){
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                res[i][j] = (res[i][j] + x[i][k] * y[k][j]) % MOD;
            }
        }
    }
    return res;
}

vector<vector<ll>> matrixPow(vector<vector<ll>> x, ll y){
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++)res[i][i] = 1;
    while(y > 0){
        if(y & 1)res = matrixMul(res, x);
        x = matrixMul(x, x);
        y >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<ll>> a = vector<vector<ll>>(n, vector<ll>(n, 0));
    for(int i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        a[x - 1][y - 1] = 1;
        a[y - 1][x - 1] = 1;
    }

    cin >> d;
    a = matrixPow(a, d);

    cout << a[0][0];

    return 0;
}