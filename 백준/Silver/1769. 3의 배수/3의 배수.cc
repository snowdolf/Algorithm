#include <iostream>

using namespace std;

string str;
int x, y, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    for (char c : str) {
        y += c - '0';
    }

    if (str.length() > 1) n = 1;
    else n = 0;
    
    while (y > 9) {
        x = y;
        y = 0;
        while (x > 0) {
            y += x % 10;
            x /= 10;
        }
        n++;
    }


    cout << n << "\n";
    if (y % 3 == 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}