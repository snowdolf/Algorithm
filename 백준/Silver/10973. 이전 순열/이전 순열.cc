#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> vec;

bool cmp(int x, int y){
    return x > y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++)cin >> vec[i];

    int idx;
    for(idx = n - 2; idx >= 0; idx--){
        if(vec[idx] > vec[idx + 1]){
            break;
        }
    }

    if(idx < 0){
        cout << "-1";
        return 0;
    }

    int midx = idx + 1;
    for(int i = idx + 2; i < n; i++){
        if(vec[midx] < vec[i] && vec[i] < vec[idx]){
            midx = i;
        }
    }

    swap(vec[idx], vec[midx]);

    sort(vec.begin() + idx + 1, vec.end(), cmp);

    for(auto i : vec)cout << i << " ";

    return 0;
}