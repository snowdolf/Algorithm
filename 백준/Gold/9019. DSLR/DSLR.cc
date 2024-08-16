#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int n;
    string cmd;
};

int t, a, b;
bool chk[10000];
queue<node> que;

int dd(int x){
    int ret = 2 * x;
    ret %= 10000;
    return ret;
}

int ss(int x){
    int ret = x - 1;
    if(ret < 0)ret = 9999;
    return ret;
}

int ll(int x){
    int ret = (x % 1000) * 10 + x / 1000;
    return ret;
}

int rr(int x){
    int ret = x / 10 + (x % 10) * 1000;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> a >> b;
        for(int i = 0; i < 10000; i++)chk[i] = false;
        while(!que.empty())que.pop();
        que.push({a, ""});
        chk[a] = true;

        while(!que.empty()){
            node qf = que.front();
            que.pop();
            if(qf.n == b){
                cout << qf.cmd << "\n";
                break;
            }
            if(!chk[dd(qf.n)]){
                que.push({dd(qf.n), qf.cmd + 'D'});
                chk[dd(qf.n)] = true;
            }
            if(!chk[ss(qf.n)]){
                que.push({ss(qf.n), qf.cmd + 'S'});
                chk[ss(qf.n)] = true;
            }
            if(!chk[ll(qf.n)]){
                que.push({ll(qf.n), qf.cmd + 'L'});
                chk[ll(qf.n)] = true;
            }
            if(!chk[rr(qf.n)]){
                que.push({rr(qf.n), qf.cmd + 'R'});
                chk[rr(qf.n)] = true;
            }
        }
    }

    return 0;
}