#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    for(int i = 1; i <= k; i++){
        cin >> n;
        vector<int> v(n);
        for(int j = 0; j < n; j++){
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        int maxGap = 0;
        for(int j = 0; j < n - 1; j++){
            maxGap = max(maxGap, v[j + 1] - v[j]);
        }
        cout << "Class " << i << "\n";
        cout << "Max " << v[n - 1] << ", Min " << v[0] << ", Largest gap " << maxGap << "\n";
    }

    return 0;
}