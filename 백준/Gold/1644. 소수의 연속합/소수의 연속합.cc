#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, l, r, sum, ans;
bool isPrime[4000010];
vector<int> pn;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    pn.push_back(2);
    for(int i = 3; i <= n; i += 2)isPrime[i] = true;
    for(int i = 3; i <= n; i += 2){
        if(isPrime[i]){
            pn.push_back(i);
            for(int j = 2 * i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }

    sum = pn[0];
    while(l <= r){
        if(sum < n){
            if(r == pn.size() - 1)break;
            sum += pn[++r];
        }
        else if(sum > n){
            sum -= pn[l++];
        }
        else{
            ans++;
            if(r == pn.size() - 1)break;
            sum += pn[++r];
        }
    }

    cout << ans;

    return 0;
}