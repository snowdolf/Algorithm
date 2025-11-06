#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct bn
{
    vector<long long> dt;
    bn() : dt(10, 0) {}
};

bn operator+(const bn &x, const bn &y)
{
    bn res;
    long long carry = 0;

    for (int i = 0; i < 10; i++)
    {
        long long sum = x.dt[i] + y.dt[i] + carry;
        res.dt[i] = sum % (long long)(1e15);
        carry = sum / (long long)(1e15);
    }

    return res;
}

void printBN(const bn &x)
{
    int idx = 9;
    while (idx > 0 && x.dt[idx] == 0) idx--;

    cout << x.dt[idx];

    for (int i = idx - 1; i >= 0; i--)
    {
        cout << setw(15) << setfill('0') << x.dt[i];
    }

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<bn> dp(251);
    dp[0].dt[0] = 1;
    dp[1].dt[0] = 1;
    dp[2].dt[0] = 3;
    
    for (int i = 3; i <= 250; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 2];
    }

    int n;
    while (cin >> n) printBN(dp[n]);

    return 0;
}