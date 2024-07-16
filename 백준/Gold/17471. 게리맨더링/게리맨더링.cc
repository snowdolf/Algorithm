#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, p[15], q[15], a, b, ans = -1;
vector<int> vec[15];
bool chk[15];
queue<int> que;

void g(int x, int y){
    for(int i = 1; i <= n; i++)chk[i] = false;
    while(!que.empty())que.pop();
    
    int target = q[1];
    int targetCount1 = target > 0 ? x : y;

    int cnt1 = 0;
    int sum1 = 0;

    que.push(1);
    chk[1] = true;
    cnt1++;
    sum1 += p[1];
    while(!que.empty()){
        int qf = que.front();
        que.pop();

        for(auto i : vec[qf]){
            if(chk[i])continue;
            if(q[i] != target)continue;
            que.push(i);
            chk[i] = true;
            cnt1++;
            sum1 += p[i];
        }
    }

    target *= -1;
    int target2Index = 2;
    while(q[target2Index] != target)target2Index++;
    int targetCount2 = target > 0 ? x : y;

    int cnt2 = 0;
    int sum2 = 0;

    que.push(target2Index);
    chk[target2Index] = true;
    cnt2++;
    sum2 += p[target2Index];
    while(!que.empty()){
        int qf = que.front();
        que.pop();

        for(auto i : vec[qf]){
            if(chk[i])continue;
            if(q[i] != target)continue;
            que.push(i);
            chk[i] = true;
            cnt2++;
            sum2 += p[i];
        }
    }

    if(cnt1 == targetCount1 && cnt2 == targetCount2){
        int res = sum1 > sum2 ? sum1 - sum2 : sum2 - sum1;
        if(ans < 0)ans = res;
        else ans = min(ans, res);
    }

    return;
}

void f(int x, int y, int z){
    if(x == n){
        if(y && z)g(y, z);
        return;
    }

    q[x + 1] = 1;
    f(x + 1, y + 1, z);
    q[x + 1] = -1;
    f(x + 1, y, z + 1);

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)cin >> p[i];

    for(int i = 1; i <= n; i++){
        cin >> a;
        while(a--){
            cin >> b;
            vec[i].push_back(b);
        }
    }

    q[1] = 1;
    f(1, 1, 0);

    cout << ans;

    return 0;
}
