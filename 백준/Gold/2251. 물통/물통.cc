#include <iostream>

using namespace std;

int a, b, c;
bool ans[205], chk[205][205][205];

void f(int x, int y, int z){
    if(chk[x][y][z]) return;

    chk[x][y][z] = true;

    if(!x) ans[z] = true;

    if(x && y < b){
        if(x < (b - y)) f(0, x + y, z);
        else f(x - (b - y), b, z);
    }
    if(x && z < c){
        if(x < (c - z)) f(0, y, x + z);
        else f(x - (c - z), y, c);
    }
    if(y && x < a){
        if(y < (a - x)) f(x + y, 0, z);
        else f(a, y - (a - x), z);
    }
    if(y && z < c){
        if(y < (c - z)) f(x, 0, y + z);
        else f(x, y - (c - z), c);
    }
    if(z && x < a){
        if(z < (a - x)) f(x + z, y, 0);
        else f(a, y, z - (a - x));
    }
    if(z && y < b){
        if(z < (b - y)) f(x, y + z, 0);
        else f(x, b, z - (b - y));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    f(0, 0, c);

    for(int i = 0; i <= 200; i++){
        if(ans[i]){
            cout << i << " ";
        }
    }

    return 0;
}