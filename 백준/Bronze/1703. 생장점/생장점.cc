#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        int a;
        cin >> a;

        if (a == 0) break;

        int ans = 1;

        while (a--)
        {
            int x, y;
            cin >> x >> y;

            ans = ans * x - y;
        }

        cout << ans << "\n";
    }

    return 0;
}