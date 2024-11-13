#include <iostream>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        string a, b;
        int x[26] = {};

        cin >> a >> b;

        for(auto ch : a)x[ch - 'a']++;
        for(auto ch : b)x[ch - 'a']--;

        bool chk = true;
        for(int i : x){
            if(i != 0){
                chk = false;
                break;
            }
        }

        cout << (chk ? "Possible\n" : "Impossible\n");
    }

    return 0;
}