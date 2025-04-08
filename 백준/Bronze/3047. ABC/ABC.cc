#include <iostream>
#include <algorithm>

using namespace std;

int a[3];
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cin >> str;

    for(auto ch : str){
        cout << a[ch - 'A'] << " ";
    }

    return 0;
}