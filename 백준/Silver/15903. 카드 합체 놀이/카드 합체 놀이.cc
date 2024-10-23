#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int n, m;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int cnt;
        cin >> cnt;
        pq.push(cnt);
    }

    while(m--){
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        a += b;

        pq.push(a);
        pq.push(a);
    }

    ll sum = 0;
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }

    cout << sum;

    return 0;
}