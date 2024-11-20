#include <iostream>
#include <vector>

using namespace std;

int n, arr[10];
vector<int> vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)cin >> arr[i];

    vec.push_back(n);
    for(int i = n - 2; i >= 0; i--){
        vec.insert(vec.begin() + arr[i], i + 1);
    }

    for(auto i : vec)cout << i << " ";

    return 0;
}