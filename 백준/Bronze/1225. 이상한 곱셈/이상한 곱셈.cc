#include <iostream>

using namespace std;

string sa, sb;
long long a, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> sa >> sb;

    for(auto i : sa)a += i - '0';
    for(auto j : sb)b += j - '0';

    cout << a * b;

    return 0;
}