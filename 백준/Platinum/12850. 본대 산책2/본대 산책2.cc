#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll d;
vector<vector<ll>> a;

vector<vector<ll>> matrixMul(vector<vector<ll>> x, vector<vector<ll>> y){
    vector<vector<ll>> res(8, vector<ll>(8, 0));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            for(int k = 0; k < 8; k++){
                res[i][j] = (res[i][j] + x[i][k] * y[k][j]) % MOD;
            }
        }
    }
    return res;
}

vector<vector<ll>> matrixPow(vector<vector<ll>> x, ll n){
    vector<vector<ll>> res(8, vector<ll>(8, 0));
    for(int i = 0; i < 8; i++)res[i][i] = 1;
    while(n > 0){
        if(n & 1)res = matrixMul(res, x);
        x = matrixMul(x, x);
        n >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> d;

    a = {{0, 1, 1, 0, 0, 0, 0, 0},
         {1, 0, 1, 1, 0, 0, 0, 0},
         {1, 1, 0, 1, 1, 0, 0, 0},
         {0, 1, 1, 0, 1, 1, 0, 0},
         {0, 0, 1, 1, 0, 1, 1, 0},
         {0, 0, 0, 1, 1, 0, 0, 1},
         {0, 0, 0, 0, 1, 0, 0, 1},
         {0, 0, 0, 0, 0, 1, 1, 0}};

    a = matrixPow(a, d);

    cout << a[0][0];

    return 0;
}