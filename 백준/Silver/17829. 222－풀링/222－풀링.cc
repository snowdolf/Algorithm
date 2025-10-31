#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pooling(int n, const vector<vector<int>> &vec)
{
    if (n == 1)
    {
        return vec[0][0];
    }

    vector<vector<int>> tmp(n / 2, vector<int>(n / 2));
    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < n; j += 2)
        {
            vector<int> sq;
            sq.push_back(vec[i][j]);
            sq.push_back(vec[i][j + 1]);
            sq.push_back(vec[i + 1][j]);
            sq.push_back(vec[i + 1][j + 1]);
            sort(sq.begin(), sq.end());

            tmp[i / 2][j / 2] = sq[2];
        }
    }

    return pooling(n / 2, tmp);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }
    cout << pooling(n, vec);

    return 0;
}