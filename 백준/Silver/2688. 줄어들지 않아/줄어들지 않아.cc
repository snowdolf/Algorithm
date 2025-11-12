#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<vector<long long>> comb(75, vector<long long>(15, 0));

    for (int i = 0; i <= 73; i++)
    {
        comb[i][0] = 1;
        for (int j = 1; j <= min(i, 9); j++)
        {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    while (t--)
    {
        int n;
        cin >> n;

        cout << comb[n + 9][9] << "\n";
    }

    return 0;
}