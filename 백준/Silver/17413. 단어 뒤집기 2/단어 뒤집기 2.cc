#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
bool isSpecial;

stack<char> st;

void swapWord()
{
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, str);

    for (char c : str)
    {
        if (c == '<')
        {
            swapWord();
            isSpecial = true;
            cout << c;
        }
        else if (c == '>')
        {
            isSpecial = false;
            cout << c;
        }
        else if (isSpecial)
        {
            cout << c;
        }
        else if (c == ' ')
        {
            swapWord();
            cout << c;
        }
        else
        {
            st.push(c);
        }
    }

    swapWord();

    return 0;
}