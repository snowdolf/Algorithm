#include <iostream>
#include <vector>

using namespace std;

int n, maxLength;
vector<int> vec, dp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++)cin >> vec[i];

    dp.assign(n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(vec[j] < vec[i] && dp[j] >= dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
        if(maxLength < dp[i])maxLength = dp[i];
    }

    cout << n - maxLength;

    return 0;
}