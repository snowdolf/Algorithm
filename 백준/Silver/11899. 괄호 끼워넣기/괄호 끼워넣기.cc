#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> st;
    string s;

    cin >> s;

    for (char c : s)
    {
        if (!st.empty() && st.top() == '(' && c == ')')
        {
            st.pop();
        }
        else
        {
            st.push(c);
        }
    }

    cout << st.size();

    return 0;
}