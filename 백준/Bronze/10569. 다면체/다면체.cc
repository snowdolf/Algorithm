#include <iostream>

using namespace std;

int t, v, e;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> v >> e;
        cout << e - v + 2 << "\n";
    }

    return 0;
}