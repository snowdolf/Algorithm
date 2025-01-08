#include <iostream>

using namespace std;

int n, m, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    if(n < 2){
        ans = 1;
    }
    else if(n < 3){
        if(m < 3)ans = 1;
        else if(m < 5)ans = 2;
        else if(m < 7)ans = 3;
        else ans = 4;
    }
    else{
        if(m < 2)ans = 1;
        else if(m < 3)ans = 2;
        else if(m < 4)ans = 3;
        else if(m < 7)ans = 4;
        else ans = 5 + (m - 7);
    }

    cout << ans;

    return 0;
}