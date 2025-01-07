#include <iostream>

using namespace std;

int n, ans, numCount, upperCount, lowerCount, specialCount;
string s, special = "!@#$%^&*()-+";

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for(auto c : s){
        if('0' <= c && c <= '9')numCount++;
        if('A' <= c && c <= 'Z')upperCount++;
        if('a' <= c && c <= 'z')lowerCount++;
        for(auto sl : special)if(c == sl)specialCount++;
    }

    if(!numCount)ans++;
    if(!upperCount)ans++;
    if(!lowerCount)ans++;
    if(!specialCount)ans++;

    while((s.length() + ans) < 6)ans++;
    cout << ans;

    return 0;
}