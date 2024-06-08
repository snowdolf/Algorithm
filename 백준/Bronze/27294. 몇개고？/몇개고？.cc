#include <iostream>

using namespace std;

int t, s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> s;

    if(s || !(12 <= t && t <= 16))cout << "280";
    else cout << "320";

    return 0;
}