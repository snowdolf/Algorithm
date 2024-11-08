#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> leftQ;
priority_queue<int, vector<int>, greater<int>> rightQ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        int cnt; cin >> cnt;

        if(leftQ.size() == rightQ.size())leftQ.push(cnt);
        else rightQ.push(cnt);

        if(!rightQ.empty() && leftQ.top() > rightQ.top()){
            int lt = leftQ.top(); leftQ.pop();
            int rt = rightQ.top(); rightQ.pop();

            leftQ.push(rt);
            rightQ.push(lt);
        }

        cout << leftQ.top() << "\n";
    }

    return 0;
}