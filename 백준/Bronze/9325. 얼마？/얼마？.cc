#include <iostream>

using namespace std;

int t, s, n, q, p;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--){
        cin >> s >> n;
        while(n--){
            cin >> q >> p;
            s += p * q;
        }
        cout << s << "\n";
    }

    return 0;
}