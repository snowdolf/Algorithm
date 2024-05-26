#include <iostream>

using namespace std;

long long n, res = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < 5; i++)res *= (n - i);
    for(int i = 0; i < 5; i++)res /= (i + 1);

    cout << res;

    return 0;
}