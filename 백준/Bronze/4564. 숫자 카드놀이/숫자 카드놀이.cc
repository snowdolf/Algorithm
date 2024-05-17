#include <iostream>

using namespace std;

int n, cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> n;
        if(!n)break;

        cout << n << " ";
        while(n > 9){
            cnt = n;
            n = 1;
            while(cnt){
                n *= (cnt % 10);
                cnt /= 10;
            }
            cout << n << " ";
        }

        cout << "\n";
    }

    return 0;
}