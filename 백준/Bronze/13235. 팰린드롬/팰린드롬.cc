#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a;

    b = a;
    reverse(a.begin(), a.end());

    if (a == b) cout << "true\n";
    else cout << "false\n";

    return 0;
}