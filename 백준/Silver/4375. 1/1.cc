#include <iostream>

using namespace std;

int n, cnt, ans;

void f(){
    cnt = ans = 1;
    snow:;
    while(n > cnt){
        cnt = 10 * cnt + 1;
        ans++;
    }
    cnt %= n;
    if(cnt)goto snow;

    cout << ans << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n)f();

    return 0;
}