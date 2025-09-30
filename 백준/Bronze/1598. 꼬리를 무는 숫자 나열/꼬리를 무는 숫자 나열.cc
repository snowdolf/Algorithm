#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    a--;
    b--;

    cout << abs(a / 4 - b / 4) + abs(a % 4 - b % 4) << "\n";

    return 0;
}