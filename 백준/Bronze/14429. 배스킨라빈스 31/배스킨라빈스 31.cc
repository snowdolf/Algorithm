#include <iostream>

using namespace std;

int main()
{
    int n, j, m;
    cin >> n;

    int minNum, minLen = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> j >> m;

        int cnt = 2 * ((j - 1) / (m + 1) + 1);
        if (cnt < minLen)
        {
            minNum = i;
            minLen = cnt;
        }
    }
    cout << minNum << " " << minLen;

    return 0;
}