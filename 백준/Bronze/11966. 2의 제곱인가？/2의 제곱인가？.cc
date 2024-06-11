#include <iostream>

using namespace std;

long long n, ans = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n > 1){
        if(n % 2){
            ans = 0;
            break;
        }
        n /= 2;
    }

    cout << ans;

    return 0;
}