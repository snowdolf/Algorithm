#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    map<string, int> mp;
    for (int i = n; i <= m; i++)
    {
        vector<int> digits;
        int num = i;
        while (num > 0)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());

        string str = "";
        for (auto &d : digits)
        {
            switch (d)
            {
            case 0:
                str += "zero ";
                break;
            case 1:
                str += "one ";
                break;
            case 2:
                str += "two ";
                break;
            case 3:
                str += "three ";
                break;
            case 4:
                str += "four ";
                break;
            case 5:
                str += "five ";
                break;
            case 6:
                str += "six ";
                break;
            case 7:
                str += "seven ";
                break;
            case 8:
                str += "eight ";
                break;
            case 9:
                str += "nine ";
                break;
            default:
                break;
            }
        }
        mp[str] = i;
    }

    int cnt = 0;
    for (auto [_, val] : mp)
    {
        cout << val << " ";
        if (++cnt % 10 == 0) cout << "\n";
    } 

    return 0;
}