#include <iostream>

using namespace std;

int n, cnt;

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        char ch;
        scanf("%c", &ch);
        if(ch == 'L')cnt++;
    }

    cnt /= 2;
    if(cnt)cnt--;

    cout << n - cnt;

    return 0;
}