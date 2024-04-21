#include <iostream>
#include <stack>

using namespace std;

string s;
bool isEye = true;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.length() % 2)
        {
            isEye = false;
            break;
        }
        if (i == s.length() / 2 - 1)
            if (s[i] != '(')
            {
                isEye = false;
                break;
            }
            else if (i == s.length() / 2)
                if (s[i] != ')')
                {
                    isEye = false;
                    break;
                }
                else
                {
                    if (s[i] != '|')
                    {
                        isEye = false;
                        break;
                    }
                }
    }
    if (isEye)
        cout << "correct";
    else
        cout << "fix";

    return 0;
}