#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        int x;
        cin >> x;
        sum += 5 * x;
    }
    cout << sum;

    return 0;
} 