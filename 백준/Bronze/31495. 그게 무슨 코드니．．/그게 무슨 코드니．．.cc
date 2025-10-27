#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    if (s.front() != '"' || s.back() != '"' || s.size() < 3)
    {
        cout << "CE" << endl;
    }
    else
    {
        cout << s.substr(1, s.size() - 2) << endl;
    }

    return 0;
}