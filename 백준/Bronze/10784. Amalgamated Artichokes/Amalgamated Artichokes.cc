#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double price(int p, int a, int b, int c, int d, int k)
{
    return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;

    double ans = 0, maxPrice = price(p, a, b, c, d, 1);
    for (int i = 2; i <= n; i++)
    {
        double currentPrice = price(p, a, b, c, d, i);
        if (currentPrice > maxPrice)
        {
            maxPrice = currentPrice;
        }
        else
        {
            ans = max(ans, maxPrice - currentPrice);
        }
    }
    cout << fixed << setprecision(6) << ans;

    return 0;
}