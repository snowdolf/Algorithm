#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int t, n, arr[100010];
string p, xx;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> p >> n >> xx;
        xx = xx.substr(1, xx.length() - 2);

        bool isSuccess = true, isReverse = false;
        int l = 0, r = 0;

        istringstream ss(xx);
        string stringBuffer;

        while (getline(ss, stringBuffer, ','))
        {
            arr[r++] = stoi(stringBuffer);
        }

        for (int i = 0; i < p.length(); i++)
        {
            if (p[i] == 'R')
            {
                isReverse = !isReverse;
            }
            if (p[i] == 'D')
            {
                if (l == r)
                {
                    isSuccess = false;
                    break;
                }
                else if (isReverse)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }

        if (isSuccess)
        {
            cout << "[";
            if (isReverse)
            {
                for (int i = r - 1; i >= l; i--)
                {
                    cout << arr[i];
                    if (i > l)
                        cout << ",";
                }
            }
            else
            {
                for (int i = l; i < r; i++)
                {
                    cout << arr[i];
                    if (i < r - 1)
                        cout << ",";
                }
            }
            cout << "]\n";
        }
        else
        {
            cout << "error\n";
        }
    }

    return 0;
}