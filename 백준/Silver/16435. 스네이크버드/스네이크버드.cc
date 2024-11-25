#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
vector<int> fruit;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    fruit.assign(n, 0);
    for(int i = 0; i < n; i++)cin >> fruit[i];

    sort(fruit.begin(), fruit.end());

    for(auto i : fruit){
        if(i > l)break;
        l++;
    }

    cout << l;

    return 0;
}