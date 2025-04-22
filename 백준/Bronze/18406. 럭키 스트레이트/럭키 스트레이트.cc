#include <iostream>

using namespace std;

string n;
int a, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n.size() / 2; i++)
    {
        a += n[i] - '0';
        b += n[n.size() - 1 - i] - '0';
    }

    if (a == b)
        cout << "LUCKY";
    else
        cout << "READY";

    return 0;
}