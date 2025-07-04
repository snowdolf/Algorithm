#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    for (int i = 1; i <= t; i++)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);

        vector<int> af(26, 0), bf(26, 0);
        for (char c : a) af[c - 'a']++;
        for (char c : b) bf[c - 'a']++;

        int ans = 0;
        for (int j = 0; j < 26; j++) ans += abs(af[j] - bf[j]);

        cout << "Case #" << i << ": " << ans << "\n";
    }

    return 0;
}