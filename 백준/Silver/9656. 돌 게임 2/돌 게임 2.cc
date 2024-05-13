#include <iostream>

using namespace std;

int n;
bool dt[1010] = {false, false, true, false};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 4; i <= n; i++)
    {
        if (!dt[i - 1] || !dt[i - 3])
            dt[i] = true;
        else
            dt[i] = false;
    }

    if (dt[n])
        cout << "SK";
    else
        cout << "CY";

    return 0;
}