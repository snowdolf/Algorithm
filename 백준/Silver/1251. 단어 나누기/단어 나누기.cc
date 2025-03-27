#include <iostream>

using namespace std;

string str, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for(int i = 1; i < str.size() - 1; i++){
        for(int j = i + 1; j < str.size(); j++){
            string tmp = "";
            for(int k = i - 1; k >= 0; k--) tmp += str[k];
            for(int k = j - 1; k >= i; k--) tmp += str[k];
            for(int k = str.size() - 1; k >= j; k--) tmp += str[k];
            if(ans == "" || tmp < ans) ans = tmp;
        }
    }

    cout << ans;

    return 0;
}