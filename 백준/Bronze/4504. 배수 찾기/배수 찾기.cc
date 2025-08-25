#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n;

    while(true)
    {
        cin >> k;
        if(k == 0) break;

        cout << k << " is ";
        cout << (k % n ? "NOT " : "") << "a multiple of " << n << ".\n";
    }

    return 0;
}