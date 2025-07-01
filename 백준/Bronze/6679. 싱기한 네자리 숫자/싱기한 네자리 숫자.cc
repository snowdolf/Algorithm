#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1000; i <= 9999; i++)
    {
        int cnt10 = 0, cnt12 = 0, cnt16 = 0;

        int n = i;
        while (n > 0)
        {
            cnt10 += n % 10;
            n /= 10;
        }

        n = i;
        while (n > 0)
        {
            cnt12 += n % 12;
            n /= 12;
        }

        n = i;
        while (n > 0)
        {
            cnt16 += n % 16;
            n /= 16;
        }

        if (cnt10 == cnt12 && cnt10 == cnt16)
        {
            cout << i << "\n";
        }
    }

    return 0;
}