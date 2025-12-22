#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        string s;
        getline(cin, s);

        vector<string> v;
        string ss = "";

        for (char c : s)
        {
            if (c == ' ')
            {
                v.push_back(ss);
                ss = "";
            }
            else
            {
                ss += c;
            }
        }
        v.push_back(ss);

        cout << "god";
        for (int i = 1; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << "\n";
    }

    return 0;
}