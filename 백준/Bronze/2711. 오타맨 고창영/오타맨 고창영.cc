#include <iostream>

using namespace std;

int t, n;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> str;
        for(int i = 1; i <= str.size(); i++){
            if(i != n)cout << str[i - 1];
        }
        cout << "\n";
    }

    return 0;
}