#include <iostream>

using namespace std;

int n, a, b;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> str;
    for(auto i : str){
        if(i == 'A')a++;
        else b++;
    }

    if(a > b)cout << "A";
    else if(a < b)cout << "B";
    else cout << "Tie";

    return 0;
}