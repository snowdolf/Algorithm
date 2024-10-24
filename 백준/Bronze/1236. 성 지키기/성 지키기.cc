#include <iostream>

using namespace std;

int n, m;
char castle[55][55];
bool chk[55][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++){
        cin >> castle[i][j];
        if(castle[i][j] == 'X'){
            chk[i][0] = true;
            chk[j][1] = true;
        }
    }

    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(!chk[i][0])a++;
    }
    for(int i = 0; i < m; i++){
        if(!chk[i][1])b++;
    }

    cout << (a > b ? a : b);

    return 0;
}