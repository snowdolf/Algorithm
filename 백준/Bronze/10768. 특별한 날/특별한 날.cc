#include <iostream>

using namespace std;

int a, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    if(a < 2)cout << "Before";
    else if(a > 2)cout << "After";
    else if(b < 18)cout << "Before";
    else if(b > 18)cout << "After";
    else cout << "Special";

    return 0;
}
