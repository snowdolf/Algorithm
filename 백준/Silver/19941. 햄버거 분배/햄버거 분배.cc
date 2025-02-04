#include <iostream>
#include <algorithm>

using namespace std;

int n, k, ans;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> str;

    for(int i = 0; i < n; i++){
        if(str[i] == 'P'){
            for(int j = max(0, i - k); j <= min(n - 1, i + k); j++){
                if(str[j] == 'H'){
                    str[j] = 'N';
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans;

    return 0;
}