#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        string str;
        cin >> str;

        int a, b, c;
        a = 10 * (str[0] - '0') + (str[1] - '0');
        b = 10 * (str[3] - '0') + (str[4] - '0');
        c = 10 * (str[6] - '0') + (str[7] - '0');

        vector<bool> h(6, false), m(6, false), s(6, false);

        int x = a, y = 32, z = 0;
        while (x > 0)
        {
            if (x >= y)
            {
                x -= y;
                h[z] = true;
            }
            y /= 2;
            z++;
        }

        x = b, y = 32, z = 0;
        while (x > 0)
        {
            if (x >= y)
            {
                x -= y;
                m[z] = true;
            }
            y /= 2;
            z++;
        }

        x = c, y = 32, z = 0;
        while (x > 0)
        {
            if (x >= y)
            {
                x -= y;
                s[z] = true;
            }
            y /= 2;
            z++;
        }

        for (int i = 0; i < 6; i++)
        {
            cout << (h[i] ? '1' : '0');
            cout << (m[i] ? '1' : '0');
            cout << (s[i] ? '1' : '0');
        }
        cout << " ";

        for (int i = 0; i < 6; i++) cout << (h[i] ? '1' : '0');
        for (int i = 0; i < 6; i++) cout << (m[i] ? '1' : '0');
        for (int i = 0; i < 6; i++) cout << (s[i] ? '1' : '0');
        cout << "\n";
    }

    return 0;
}