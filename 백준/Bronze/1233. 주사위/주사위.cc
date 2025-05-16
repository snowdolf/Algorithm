#include <iostream>

using namespace std;

int x, y, z, count[100], ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y >> z;
    for(int i = 1; i <= x; i++)for(int j = 1; j <= y; j++)for(int k = 1; k <= z; k++){
        count[i + j + k]++;
    }
    for(int i = 3; i <= x + y + z; i++){
        if(count[i] > count[ans]){
            ans = i;
        }
    }

    cout << ans;

    return 0;
}