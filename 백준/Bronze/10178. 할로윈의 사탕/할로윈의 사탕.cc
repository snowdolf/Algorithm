#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, c, v;
    cin >> t;

    while(t--)
    {
        cin >> c >> v;
        cout << "You get " << c / v << " piece(s) and your dad gets " << c % v << " piece(s).\n";
    }

    return 0;
}