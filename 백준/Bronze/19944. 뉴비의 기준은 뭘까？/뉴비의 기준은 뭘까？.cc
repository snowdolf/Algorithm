#include <iostream>

using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    if(m <= 2)cout << "NEWBIE!";
    else if(m <= n)cout << "OLDBIE!";
    else cout << "TLE!";

    return 0;
}