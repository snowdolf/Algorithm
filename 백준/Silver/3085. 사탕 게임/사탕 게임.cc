#include <iostream>
#include <algorithm>

using namespace std;

int n;
char board[55][55];

int cal(){
    int ret = 0;

    for(int i = 0; i < n; i++){
        int cnt = 1;
        for(int j = 1; j < n; j++){
            if(board[i][j] == board[i][j - 1])cnt++;
            else cnt = 1;
            ret = max(ret, cnt);
        }
    }

    for(int i = 0; i < n; i++){
        int cnt = 1;
        for(int j = 1; j < n; j++){
            if(board[j][i] == board[j - 1][i])cnt++;
            else cnt = 1;
            ret = max(ret, cnt);
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++)cin >> board[i][j];

    int ans = 0;

    for(int i = 0; i < n - 1; i++)for(int j = 0; j < n; j++){
        swap(board[i][j], board[i + 1][j]);
        ans = max(ans, cal());
        swap(board[i][j], board[i + 1][j]);
    }

    for(int i = 0; i < n; i++)for(int j = 0; j < n - 1; j++){
        swap(board[i][j], board[i][j + 1]);
        ans = max(ans, cal());
        swap(board[i][j], board[i][j + 1]);
    }

    cout << ans;

    return 0;
}