#include <iostream>

using namespace std;

int n;
bool dt[1010] = {false, true, false, true, true};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 5; i <= n; i++)
    {
        if (!dt[i - 1] || !dt[i - 3] || !dt[i - 4])
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