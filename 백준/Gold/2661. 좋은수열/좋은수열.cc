#include <iostream>
#include <string>

using namespace std;

int n;
string str = "";

bool isGood(){
    for(int i = 1; i <= str.length() / 2; i++){
        string l = str.substr(str.length() - 2 * i, i);
        string r = str.substr(str.length() - i, i);
        if(l == r)return false;
    }
    return true;
}

bool f(int x){
    if(!isGood())return false;

    if(x == n){
        cout << str;
        return true;
    }

    for(int i = 1; i <= 3; i++){
        str.push_back('0' + i);
        if(f(x + 1))return true;
        str.pop_back();
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    f(0);

    return 0;
}