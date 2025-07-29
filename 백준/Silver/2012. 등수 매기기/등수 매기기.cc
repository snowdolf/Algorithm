#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(arr[i] - (i + 1));
    }
    cout << ans;

    return 0;
}