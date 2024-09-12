#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, d;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d;
    cout << min(a + d, b + c);

    return 0;
}