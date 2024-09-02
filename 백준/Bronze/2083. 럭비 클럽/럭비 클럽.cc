#include <iostream>

using namespace std;

string s;
int a, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> s >> a >> b;
        if(s == "#")break;
        if(a > 17 || b >= 80)cout << s << " Senior\n";
        else cout << s << " Junior\n";
    }

    return 0;
}