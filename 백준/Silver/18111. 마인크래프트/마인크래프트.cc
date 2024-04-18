#include <iostream>

using namespace std;

int n, m, b, g[505][505];
int t = 1000000000, h = -1, hmax = -1, hmin = 300;

void f(int height, int time, int bag){
    if(height < hmin)return;

    bool isSuccess = true;

    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++){
        if(g[i][j] > height){
            time += 2 * (g[i][j] - height);
            bag += (g[i][j] - height);
        }
    }

    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++){
        if(g[i][j] < height){
            if(bag < (height - g[i][j])){
                isSuccess = false;
                break;
            }
            else{
                time += (height - g[i][j]);
                bag -= (height - g[i][j]);
            }
        }
    }

    if(isSuccess){
        if(t > time){
            t = time;
            h = height;
        }
        else if(t == time && h < height){
            t = time;
            h = height;
        }
    }

    f(height - 1, 0, b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> b;
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++){
        cin >> g[i][j];
        hmax = hmax < g[i][j] ? g[i][j] : hmax;
        hmin = hmin > g[i][j] ? g[i][j] : hmin;
    }

    f(hmax, 0, b);

    cout << t << " " << h;

    return 0;
}