#include <iostream>

using namespace std;

int sdk[10][10];
bool chk[3][10][10];

int square(int x, int y){
    return (x / 3) * 3 + (y / 3);
}

bool f(int z){
    if(z == 81)return true;

    int x = z / 9, y = z % 9;

    if(sdk[x][y])return f(z + 1);
    else{
        for(int i = 1; i <= 9; i++){
            if(!chk[0][x][i] && !chk[1][y][i] && !chk[2][square(x, y)][i]){
                chk[0][x][i] = chk[1][y][i] = chk[2][square(x, y)][i] = true;
                sdk[x][y] = i;
                if(f(z + 1))return true;
                sdk[x][y] = 0;
                chk[0][x][i] = chk[1][y][i] = chk[2][square(x, y)][i] = false;
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 9; i++){
        string str;
        cin >> str;
        for(int j = 0; j < 9; j++){ 
            sdk[i][j] = str[j] - '0';
            if(sdk[i][j]){
                chk[0][i][sdk[i][j]] = chk[1][j][sdk[i][j]] = chk[2][square(i, j)][sdk[i][j]] = true;
            }
        }
    }

    f(0);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << sdk[i][j];
        }
        cout << "\n";
    }

    return 0;
}