#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    cout << max(c - b, b - a) - 1;

    return 0;
}