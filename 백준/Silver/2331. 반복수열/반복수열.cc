#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int cal(int x, int y){
    int res = 0;

    while(x){
        res += (int)pow(x % 10, y);
        x /= 10;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, p;
    cin >> a >> p;

    vector<int> d;
    map<int, int> chk;

    d.push_back(a);
    chk[a] = d.size();

    while(1){
        int cnt = cal(d.back(), p);
        if(chk.find(cnt) == chk.end()){
            d.push_back(cnt);
            chk[cnt] = d.size();
        }
        else{
            cout << chk[cnt] - 1;
            break;
        }
    }

    return 0;
}