#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    for(int i = 0; i < str.size() - 1; i++){
        int left = 1, right = 1, idx = 0;
        for(idx = 0; idx <= i; idx++){
            left *= (str[idx] - '0');
        }
        for(idx = i + 1; idx < str.size(); idx++){
            right *= (str[idx] - '0');
        }
        if(left == right){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}