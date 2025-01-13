#include <iostream>

using namespace std;

int x, y, t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> x >> y;
        cout << x + y << "\n";
    }
    
    return 0;
}