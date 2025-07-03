#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;

        for (auto c : s)
        {
            cout << (char)((a * (c - 'A') + b) % 26 + 'A');
        }
        cout << '\n';
    }

    return 0;
}