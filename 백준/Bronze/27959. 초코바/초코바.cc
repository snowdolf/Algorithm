#include <iostream>

using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    if(100 * n >= m)cout << "Yes";
    else cout << "No";

    return 0;
}