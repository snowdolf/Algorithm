#include <iostream>
#include <stack>

using namespace std;

int solve(stack<char> &st)
{
    int ret = 0;

    st.pop();

    int count = 0;

    while (true)
    {
        char c = st.top();

        if (c == ')')
        {
            count += solve(st);
        }
        else if (c == '(')
        {
            st.pop();
            break;
        }
        else
        {
            count++;
            st.pop();
        }
    }

    ret = (st.top() - '0') * count;
    st.pop();

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> st;
    st.push('1');
    st.push('(');
    for (char c : str)
    {
        st.push(c);
    }
    st.push(')');

    cout << solve(st) << "\n";

    return 0;
}