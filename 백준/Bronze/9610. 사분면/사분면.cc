#include <iostream>

using namespace std;

int a, b, c, d, e, x, y, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        cin >> x >> y;
        if(!x || !y)e++;
        else if(x > 0 && y > 0)a++;
        else if(x < 0 && y > 0)b++;
        else if(x < 0 && y < 0)c++;
        else if(x > 0 && y < 0)d++;
    }

    cout << "Q1: " << a << "\n";
    cout << "Q2: " << b << "\n";
    cout << "Q3: " << c << "\n";
    cout << "Q4: " << d << "\n";
    cout << "AXIS: " << e << "\n";

    return 0;
}
