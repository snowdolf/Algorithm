#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if ((str[str.size() - 1] - '0') % 2) cout << "odd\n";
        else cout << "even\n";
    }

    return 0;
}