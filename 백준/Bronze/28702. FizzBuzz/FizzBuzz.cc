#include <iostream>
#include <string>

using namespace std;

int a[3], n;
string str[3];

bool isNum(string s){
    for(auto i : s){
        if(!isdigit(i)){
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 3; i++)cin >> str[i];

    for(int i = 0; i < 3; i++){
        if(isNum(str[i])){
            n = stoi(str[i]) + 3 - i;
            break;
        }
    }

    if(n % 15 == 0)cout << "FizzBuzz";
    else if(n % 3 == 0)cout << "Fizz";
    else if(n % 5 == 0)cout << "Buzz";
    else cout << n;

    return 0;
}