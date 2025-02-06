#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d[55][55], score = 100;
vector<int> vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++)d[i][j] = 100;
    for(int i = 1; i <= n; i++)d[i][i] = 0;

    while(1){
        int a, b;
        cin >> a >> b;
        if(a < 0)break;
        d[a][b] = d[b][a] = 1;
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(i != j){
                cnt = max(cnt, d[i][j]);
            }
        }
        if(cnt < score){
            score = cnt;
            vec.clear();
            vec.push_back(i);
        }
        else if(cnt == score){
            vec.push_back(i);
        }
    }

    cout << score << " " << vec.size() << "\n";
    for(auto i : vec)cout << i << " ";

    return 0;
}