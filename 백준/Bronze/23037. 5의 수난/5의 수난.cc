#include <iostream>
#include <cmath>

using namespace std;

int n, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n){
        ans += (int)pow(n % 10, 5);
        n /= 10;
    }
    cout << ans;

    return 0;
}