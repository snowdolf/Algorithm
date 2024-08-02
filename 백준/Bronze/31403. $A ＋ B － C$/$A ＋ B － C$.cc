#include <iostream>
#include <string>

using namespace std;

int a, b, c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    cout << a + b - c << "\n";
    cout << stoi(to_string(a) + to_string(b)) - c;

    return 0;
}