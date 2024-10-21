#include <iostream>
#include <queue>

using namespace std;

int n, w, l;
queue<int> leftQ, bridge, rightQ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> l;

    for(int i = 0; i < n; i++){
        int weight;
        cin >> weight;
        rightQ.push(weight);
    }

    for(int i = 0; i < w; i++)bridge.push(0);

    int sum = 0, cnt = 0, time = 0;
    
    while(leftQ.size() < n){
        if(bridge.front()){
            leftQ.push(bridge.front());
            sum -= bridge.front();
            cnt--;
        }
        bridge.pop();

        if(!rightQ.empty() && cnt <= w && (sum + rightQ.front()) <= l){
            bridge.push(rightQ.front());
            sum += rightQ.front();
            cnt++;
            rightQ.pop();
        }
        else bridge.push(0);

        time++;
    }

    cout << time;

    return 0;
}