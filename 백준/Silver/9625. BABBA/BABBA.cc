#include <iostream>

using namespace std;

int n, a = 1, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--){
        int cnt = a;
        a = b;
        b += cnt;
    }

    cout << a << " " << b;

    return 0;
}