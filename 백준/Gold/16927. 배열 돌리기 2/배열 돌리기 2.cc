#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, t;
int arr[305][305], brr[305][305];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;

    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)cin >> arr[i][j];

    for(int i = 0; i < min(n, m) / 2; i++){
        queue<int> que;
        for(int j = i; j < m - i - 1; j++)que.push(arr[i][j]);
        for(int j = i; j < n - i - 1; j++)que.push(arr[j][m - i - 1]);
        for(int j = m - i - 1; j > i; j--)que.push(arr[n - i - 1][j]);
        for(int j = n - i - 1; j > i; j--)que.push(arr[j][i]);

        for(int j = 0; j < t % (2 * (m + n - 4 * i - 2)); j++){
            que.push(que.front());
            que.pop();
        }

        for(int j = i; j < m - i - 1; j++){
            brr[i][j] = que.front();
            que.pop();
        }
        for(int j = i; j < n - i - 1; j++){
            brr[j][m - i - 1] = que.front();
            que.pop();
        }
        for(int j = m - i - 1; j > i; j--){
            brr[n - i - 1][j] = que.front();
            que.pop();
        }
        for(int j = n - i - 1; j > i; j--){
            brr[j][i] = que.front();
            que.pop();
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << brr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}