#include <iostream>

using namespace std;

int s, k, h;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> k >> h;
    if(s + k + h >= 100)cout << "OK";
    else if(s < k && s < h)cout << "Soongsil";
    else if(k < h)cout << "Korea";
    else cout << "Hanyang";

    return 0;
}