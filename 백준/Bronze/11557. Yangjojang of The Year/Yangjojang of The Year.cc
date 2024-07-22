#include <iostream>

using namespace std;

string s, ms;
int t, n, l, ml;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        ml = 0;
        while(n--){
            cin >> s >> l;
            if(ml < l){
                ms = s;
                ml = l;
            }
        }
        cout << ms << "\n";
    }

    return 0;
}
