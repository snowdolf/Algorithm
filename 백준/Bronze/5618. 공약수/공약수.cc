#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &num : nums) cin >> num;
    sort(nums.begin(), nums.end());

    vector<int> gcd;
    for (int i = 1; i <= nums[0]; i++)
    {
        bool chk = true;
        for (auto num : nums)
        {
            if (num % i)
            {
                chk = false;
                break;
            }
        }
        if (chk) gcd.push_back(i);
    }

    for (auto x : gcd) cout << x << "\n";

    return 0;
}