#include <iostream>

using namespace std;

int n, a, b;
string str[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> str[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(str[i][j] != '.' || str[i][j + 1] != '.')continue;
            int k = j + 2;
            while(1){
                if(k == n || str[i][k] != '.')break;
                k++;
            }
            j = k;
            a++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(str[j][i] != '.' || str[j + 1][i] != '.')continue;
            int k = j + 2;
            while(1){
                if(k == n || str[k][i] != '.')break;
                k++;
            }
            j = k;
            b++;
        }
    }

    cout << a << " " << b;

    return 0;
}