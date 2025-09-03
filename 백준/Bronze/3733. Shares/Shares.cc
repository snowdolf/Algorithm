#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    while(cin >> n >> x)
    {
        n++;
        cout << x / n << "\n";
    }

    return 0;
}