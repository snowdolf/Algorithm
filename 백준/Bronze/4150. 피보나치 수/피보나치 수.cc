#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct bn
{
    static const int size = 100;
    static const long long base = 1e15;

    vector<long long> dt;
    bn() : dt(100, 0) {}

    bn operator+(const bn &x) const
    {
        bn res;
        long long carry = 0;

        for (int i = 0; i < size; i++)
        {
            long long sum = dt[i] + x.dt[i] + carry;
            res.dt[i] = sum % base;
            carry = sum / base;
        }

        return res;
    }

    void print() const
    {
        int idx = size - 1;
        while (idx > 0 && dt[idx] == 0) idx--;

        cout << dt[idx];
        for (int i = idx - 1; i >= 0; i--)
        {
            cout << setw(15) << setfill('0') << dt[i];
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<bn> fib(3);
    fib[1].dt[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i % 3] = fib[(i - 1) % 3] + fib[(i - 2) % 3];
    }

    fib[n % 3].print();

    return 0;
}