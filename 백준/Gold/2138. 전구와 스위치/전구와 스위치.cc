#include <iostream>

using namespace std;

int n, ans = -1, cnt;
string before, after, tmp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> before >> after;

    tmp = before;
    for(int i = 0; i < tmp.size() - 1; i++){
        if(tmp[i] != after[i]){
            cnt++;
            for(int j = 0; j < 3; j++){
                if(i + j < tmp.size()){
                    if(tmp[i + j] == '0'){
                        tmp[i + j] = '1';
                    }else{
                        tmp[i + j] = '0';
                    }
                }
            }
        }
    }
    if(tmp == after){
        ans = cnt;
    }

    tmp = before;
    cnt = 1;
    for(int i = 0; i < 2; i++){
        if(tmp[i] == '0'){
            tmp[i] = '1';
        }else{
            tmp[i] = '0';
        }
    }
    for(int i = 0; i < tmp.size() - 1; i++){
        if(tmp[i] != after[i]){
            cnt++;
            for(int j = 0; j < 3; j++){
                if(i + j < tmp.size()){
                    if(tmp[i + j] == '0'){
                        tmp[i + j] = '1';
                    }else{
                        tmp[i + j] = '0';
                    }
                }
            }
        }
    }
    if(tmp == after){
        if(ans == -1){
            ans = cnt;
        }else{
            ans = min(ans, cnt);
        }
    }

    cout << ans;

    return 0;
}