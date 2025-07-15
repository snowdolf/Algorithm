#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    while(n--)
    {
        int a, b;
        cin >> a >> b;

        switch (a)
        {
        case 136:
            ans += 1000;
            break;
        case 142:
            ans += 5000;
            break;
        case 148:
            ans += 10000;
            break;
        default:
            ans += 50000;
            break;
        }
    }
    cout << ans;

    return 0;
}