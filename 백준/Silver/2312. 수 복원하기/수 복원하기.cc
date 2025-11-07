#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<int, int> divisor;

        while (n % 2 == 0)
        {
            divisor[2]++;
            n /= 2;
        }
        for (int i = 3; i <= n; i += 2)
        {
            while (n % i == 0)
            {
                divisor[i]++;
                n /= i;
            }
        }
        for (auto &[key, value] : divisor)
        {
            cout << key << " " << value << "\n";
        }
    }

    return 0;
}