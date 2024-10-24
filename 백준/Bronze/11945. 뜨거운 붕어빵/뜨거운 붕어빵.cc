#include <iostream>

using namespace std;

int n, m;
char bread[15][15];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)for(int j = 0; j < m ; j++)cin >> bread[i][j];

    for(int i = 0; i < n; i++){
        for(int j = m - 1; j >= 0; j--){
            cout << bread[i][j];
        }
        cout << "\n";
    }

    return 0;
}