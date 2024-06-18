#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, arr[300010], idx, sum, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)cin >> arr[i];
    sort(arr, arr + n);

    idx = (int)round((double)n * 15 / 100);
    for(int i = idx; i < n - idx; i++)sum += arr[i];

    ans = (int)round((double)sum / (n - 2 * idx));
    if(!n) ans = 0;
    cout << ans;

    return 0;
}