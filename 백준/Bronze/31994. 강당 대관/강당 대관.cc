#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 7, n = 0;
    string a;

    while(t--)
    {
        string s;
        int x;
        cin >> s >> x;

        if (n < x) a = s, n = x;
    }
    cout << a;

    return 0;
}