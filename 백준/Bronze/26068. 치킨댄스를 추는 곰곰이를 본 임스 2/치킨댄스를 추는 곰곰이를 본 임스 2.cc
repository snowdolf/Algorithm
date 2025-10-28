#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0;
    cin >> n;

    while(n--)
    {
        string s;
        cin >> s;

        int m = stoi(s.substr(2, s.length() - 2));
        if (m <= 90) cnt++;
    }
    cout << cnt;

    return 0;
} 