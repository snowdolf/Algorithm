#include <iostream>
#include <algorithm>

using namespace std;

int n, dtmax[2][3], dtmin[2][3], a, b, c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        dtmax[1][0] = max(dtmax[0][0], dtmax[0][1]) + a;
        dtmax[1][1] = max(max(dtmax[0][0], dtmax[0][1]), dtmax[0][2]) + b;
        dtmax[1][2] = max(dtmax[0][1], dtmax[0][2]) + c;
        for(int i = 0; i < 3; i++)dtmax[0][i] = dtmax[1][i];
        dtmin[1][0] = min(dtmin[0][0], dtmin[0][1]) + a;
        dtmin[1][1] = min(min(dtmin[0][0], dtmin[0][1]), dtmin[0][2]) + b;
        dtmin[1][2] = min(dtmin[0][1], dtmin[0][2]) + c;
        for(int i = 0; i < 3; i++)dtmin[0][i] = dtmin[1][i];
    }

    cout << max(max(dtmax[0][0], dtmax[0][1]), dtmax[0][2]) 
    << " " << min(min(dtmin[0][0], dtmin[0][1]), dtmin[0][2]);

    return 0;
}