#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(1010, vector<int>(1010, 0));
    vector<vector<char>> ch(1010, vector<char>(1010));
    vector<vector<pair<int, int>>> path(1010, vector<pair<int, int>>(1010, {0, 0}));

    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ch[i][j] = a[i - 1];
                path[i][j] = {i - 1, j - 1};
            }
            else
            {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
                ch[i][j] = dp[i - 1][j] > dp[i][j - 1] ? ch[i - 1][j] : ch[i][j - 1];
                path[i][j] = dp[i - 1][j] > dp[i][j - 1] ? make_pair(i - 1, j) : make_pair(i, j - 1);
            }
        }
    }

    cout << dp[a.size()][b.size()] << "\n";

    string lcs;
    for(pair<int, int> x = {a.size(), b.size()}; x.first && x.second;)
    {
        if (a[x.first - 1] == b[x.second - 1])
        {
            lcs += ch[x.first][x.second];
        }
        x = path[x.first][x.second];
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs;

    return 0;
}