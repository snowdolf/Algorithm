#include <iostream>

using namespace std;

int n, m[105], s[105], b[105], ans;

bool chkNum(int x){
    bool ret = true;

    int p = x % 10;
    x /= 10;
    int q = x % 10;
    x /= 10;
    int r = x;

    if(p == q || q == r || r == p)ret = false;
    if(!p || !q || !r)ret = false;

    return ret;
}

bool chkGame(int idx, int x){
    bool ret = true;

    int p = x % 10;
    x /= 10;
    int q = x % 10;
    x /= 10;
    int r = x;

    x = m[idx];
    int mp = x % 10;
    x /= 10;
    int mq = x % 10;
    x /= 10;
    int mr = x;

    int ms = 0, mb = 0;

    if(p == mp)ms++;
    if(p == mq)mb++;
    if(p == mr)mb++;
    if(q == mp)mb++;
    if(q == mq)ms++;
    if(q == mr)mb++;
    if(r == mp)mb++;
    if(r == mq)mb++;
    if(r == mr)ms++;

    if(ms != s[idx] || mb != b[idx])ret = false;

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m[i] >> s[i] >> b[i];
    }

    for(int i = 123; i <= 987; i++){
        if(!chkNum(i))continue;

        bool chk = true;
        for(int j = 0; j < n && chk; j++){
            chk = chkGame(j, i);
        }
        if(chk)ans++;
    }

    cout << ans;

    return 0;
}