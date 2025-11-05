#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    while (k--)
    {
        int p, m;
        cin >> p >> m;

        int ans = 0;

        vector<bool> chk(m + 1, false);
        while (p--)
        {
            int x;
            cin >> x;

            if (!chk[x]) chk[x] = true;
            else ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}