#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> nums(n, vector<int>(3));
    vector<vector<int>> counts(101, vector<int>(3, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> nums[i][j];
            counts[nums[i][j]][j]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            if (counts[nums[i][j]][j] == 1)
            {
                sum += nums[i][j];
            }
        }
        cout << sum << "\n";
    }

    return 0;
}