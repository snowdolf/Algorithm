#include <iostream>

using namespace std;

long long n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    if (n % 2)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}