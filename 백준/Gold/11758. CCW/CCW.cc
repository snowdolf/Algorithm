#include <iostream>

using namespace std;

struct pos
{
    int x, y;
};

pos p[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 3; i++)cin >> p[i].x >> p[i].y;

    // p0p1 = (p1x - p0x, p1y - p0y, 0), p1p2 = (p2x - p1x, p2y - p1y, 0)
    int cnt = (p[1].x - p[0].x) * (p[2].y - p[1].y) - (p[1].y - p[0].y) * (p[2].x - p[1].x);

    if(cnt > 0)cout << "1";
    else if(cnt < 0)cout << "-1";
    else cout << "0";

    return 0;
}