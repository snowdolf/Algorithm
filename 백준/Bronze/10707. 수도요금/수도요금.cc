#include <iostream>

using namespace std;

int a, b, c, d, p;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d >> p;

    int cnt = b;
    if(c < p){
        cnt += d * (p - c);
    }
    cout << (a * p < cnt ? a * p : cnt);

    return 0;
}