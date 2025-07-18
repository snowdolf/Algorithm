#include <iostream>

using namespace std;

int a, b, c, d;

int main()
{
    cin >> a >> b >> c >> d;

    int x = a + d;
    int y = b + c;

    int ans = x > y ? x - y : y - x;

    cout << ans;

    return 0;
}