#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b;
vector<int> vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i <= 20; i++)vec.push_back(i);

    for(int i = 0; i < 10; i++){
        cin >> a >> b;
        reverse(vec.begin() + a, vec.begin() + b + 1);
    }

    for(int i = 1; i <= 20; i++)cout << vec[i] << " ";

    return 0;
}