#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<char> v(n);
    for (auto &x : v) cin >> x;


    int x = 0, y = 0;
    for (auto c : v)
    {
        if (c == 'D') x++;
        else y++;

        if (x - y >= 2 || y - x >= 2)
        {
            break;
        }
    }
    cout << x << ":" << y << "\n";

    return 0;
}