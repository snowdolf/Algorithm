#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; i++)
    {
        string s;
        cin >> s;

        char c = s[0];
        int cnt = 1, ans = 1;

        for (int j = 1; j < s.size(); j++)
        {
            if (s[j]  == c) cnt++;
            else
            {
                ans = max(ans, cnt);
                c = s[j];
                cnt = 1;
            }
        }
        ans = max(ans, cnt);

        cout << ans << "\n";
    }

    return 0;
}