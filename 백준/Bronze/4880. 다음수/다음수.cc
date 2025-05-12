#include <iostream>

using namespace std;

int a, b, c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> a >> b >> c;
        if(!(a || b || c)) break;

        if(b - a == c - b && a != b){
            cout << "AP " << c + (b - a) << "\n";
        }
        else{
            cout << "GP " << c * (b / a) << "\n";
        }
    }

    return 0;
}