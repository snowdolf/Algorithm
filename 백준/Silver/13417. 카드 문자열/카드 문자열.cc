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

        string ans = "";

        while (n--)
        {
            char c;
            cin >> c;

            if (ans.size() == 0 || ans[0] < c) ans += c;
            else ans = c + ans;
        }

        cout << ans << "\n";
    }

    return 0;
}