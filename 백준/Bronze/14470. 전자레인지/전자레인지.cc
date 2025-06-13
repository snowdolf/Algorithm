#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d, e, t = 0;
    cin >> a >> b >> c >> d >> e;

    if(a < 0){
        t = c * (-a);
        a = 0;
    }
    if(a == 0){
        t += d;
    }
    t += e * (b - a);

    cout << t;

    return 0;
}