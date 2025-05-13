#include <iostream>

using namespace std;

int a[10], b[10], cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 10; i++)cin >> a[i];
    for(int i = 0; i < 10; i++)cin >> b[i];
    for(int i = 0; i < 10; i++){
        if(a[i] > b[i])cnt++;
        if(a[i] < b[i])cnt--;
    }

    if(cnt > 0)cout << "A";
    if(cnt < 0)cout << "B";
    if(cnt == 0)cout << "D";

    return 0;
}