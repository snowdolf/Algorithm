#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, m, cnt;
        cin >> n;

        vector<int> vec(n);
        for(int i = 0; i < n; i++){
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());

        cin >> m;
        
        for(int i = 0; i < m; i++){
            cin >> cnt;
            cout << (binary_search(vec.begin(), vec.end(), cnt) ? 1 : 0) << "\n";
        }
    }

    return 0;
}