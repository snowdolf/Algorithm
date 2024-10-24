#include <iostream>

using namespace std;

int n;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        cin >> str;
        if(str.length() >= 6 && str.length() <= 9)cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}