#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum, sub, a, b;
    cin >> sum >> sub;
    a = (sum + sub) / 2;
    b = sum - a;

    if(sum < sub || (sum + sub) % 2) cout << -1;
    else cout << a << " " << b;

    return 0;
}