#include <iostream>

using namespace std;

int n, l = 1000, r = 0, cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        cin >> cnt;
        if(l > cnt)l = cnt;
        if(r < cnt)r = cnt;
    }

    cout << r - l;

    return 0;
}