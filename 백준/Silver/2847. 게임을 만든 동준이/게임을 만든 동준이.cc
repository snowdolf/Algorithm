#include <iostream>
#include <vector>

using namespace std;

int n, ans, cnt;
vector<int> vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++)cin >> vec[i];

    for(int i = n - 1; i > 0; i--){
        if(vec[i - 1] >= vec[i]){
            cnt = vec[i - 1] - vec[i] + 1;
            ans += cnt;
            vec[i - 1] -= cnt;
        }
    }

    cout << ans;

    return 0;
}