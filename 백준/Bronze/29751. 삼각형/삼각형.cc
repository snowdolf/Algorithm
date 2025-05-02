#include <iostream>
#include <iomanip>

using namespace std;

int w, h;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;

    float ans = w * h / 2.0f;
    
    cout << fixed << setprecision(1) << ans;

    return 0;
}