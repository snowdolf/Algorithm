#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int sum = 0, cnt = 0;
    while (n--)
    {
        int v;
        cin >> v;

        sum += v;
        cnt = cnt < v ? v : cnt;
    }

    cout << sum - cnt;

    return 0;
}