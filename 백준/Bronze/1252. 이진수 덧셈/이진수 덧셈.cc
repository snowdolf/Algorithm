#include <iostream>

using namespace std;

string a, b, c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    if(a.size() < b.size()){
        c = a;
        a = b;
        b = c;
    }
    c.clear();

    int idx = 0, cnt = 0;
    for(idx = 0; idx < b.size(); idx++){
        if(a[a.size() - 1 - idx] != b[b.size() - 1 - idx]){
            cnt++;
        }
        else if(a[a.size() - 1 - idx] == '1'){
            cnt += 2;
        }

        if(cnt % 2){
            c += '1';
        }
        else{
            c += '0';
        }

        cnt /= 2;
    }
    for(; idx < a.size(); idx++){
        if(a[a.size() - 1 - idx] == '1'){
            cnt += 1;
        }

        if(cnt % 2){
            c += '1';
        }
        else{
            c += '0';
        }

        cnt /= 2;
    }

    if(cnt){
        c += '1';
    }

    for(idx = c.size() - 1; idx >= 0; idx--){
        if(c[idx] == '1'){
            break;
        }
    }
    if(idx == -1){
        idx = 0;
    }
    for(; idx >= 0; idx--){
        cout << c[idx];
    }

    return 0;
}