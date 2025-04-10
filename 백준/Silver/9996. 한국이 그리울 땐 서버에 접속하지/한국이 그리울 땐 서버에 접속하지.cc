#include <iostream>

using namespace std;

int n;
string tmp, str1, str2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> tmp;
    str1 = tmp.substr(0, tmp.find('*'));
    str2 = tmp.substr(tmp.find('*') + 1, n - str1.length() - 1);

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp.length() >= str1.length() + str2.length())
        {
            if (tmp.substr(0, str1.length()) == str1 && tmp.substr(tmp.length() - str2.length(), str2.length()) == str2)
            {
                cout << "DA\n";
            }
            else
            {
                cout << "NE\n";
            }
        }
        else
        {
            cout << "NE\n";
        }
    }

    return 0;
}