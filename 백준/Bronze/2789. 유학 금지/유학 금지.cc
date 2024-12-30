#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str, cu = "CAMBRIDGE";
    cin >> str;
    
    for(auto c : str){
        bool chk = true;
        for(auto u : cu){
            if(c == u){
                chk = false;
                break;
            }
        }
        if(chk)cout << c;
    }

    return 0;
}