#include <iostream>

using namespace std;

int t[2][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++)for(int k = 0; k < 3; k++)cin >> t[j][k];
        for(int j = 0; j < 3; j++)t[1][j] -= t[0][j];
        if(t[1][2] < 0){
            t[1][2] += 60;
            t[1][1]--;
        }
        if(t[1][1] < 0){
            t[1][1] += 60;
            t[1][0]--;
        }
        for(int j = 0; j < 3; j++)cout << t[1][j] << " ";
        cout << "\n";
    }

    return 0;
}