#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if ((n + 1) % (n % 100)) cout << "Bye\n";
        else cout << "Good\n";
    }

    return 0;
}