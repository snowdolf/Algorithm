#include <iostream>

using namespace std;

int n, l = 1, r = 1, sum = 1, res;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (r <= n)
    {
        if (sum < n)
        {
            sum += (++r);
        }
        else if (sum > n)
        {
            sum -= (l++);
        }
        else
        {
            res++;
            sum += (++r);
            sum -= (l++);
        }
    }

    cout << res;

    return 0;
}