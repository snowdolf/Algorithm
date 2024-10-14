#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, arr[1505][1505], idx[1505];
pair<int, int> ans;
priority_queue<pair<int, int>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++)cin >> arr[i][j];

    for(int i = 0; i < n; i++){
        idx[i] = n - 1;
        pq.push({arr[idx[i]--][i], i});
    }

    for(int i = 0; i < n; i++){
        ans = pq.top();
        pq.pop();

        if(idx[ans.second] < 0)continue;
        pq.push({arr[idx[ans.second]--][ans.second], ans.second});
    }

    cout << ans.first;

    return 0;
}   