#include <iostream>

using namespace std;

int n, t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; n > 0; i++, t++){
        if(n < i) i = 1;
        n -= i;
    }

    cout << t;

    return 0;
}