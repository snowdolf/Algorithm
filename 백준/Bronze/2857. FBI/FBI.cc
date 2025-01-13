#include <iostream>

using namespace std;

int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 5; i++){
        string name;
        cin >> name;

        if(name.find("FBI") != string::npos){
            cout << i << " ";
            cnt++;
        }
    }
    if(!cnt)cout << "HE GOT AWAY!";

    return 0;
}