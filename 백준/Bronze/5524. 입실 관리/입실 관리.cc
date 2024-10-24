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
        for(auto c : str){
            if(c < 'a')cout << (char)(c + 'a' - 'A');
            else cout << c;
        }
        cout << "\n";
    }

    return 0;
}