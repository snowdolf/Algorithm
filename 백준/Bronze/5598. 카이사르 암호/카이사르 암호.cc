#include <iostream>

using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    for(int i = 0; i < str.length(); i++){
        str[i] -= 3;
        if(str[i] < 'A')str[i] += 26;
    }
    cout << str;

    return 0;
}