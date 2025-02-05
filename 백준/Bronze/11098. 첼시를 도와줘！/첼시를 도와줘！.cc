#include <iostream>

using namespace std;

int n, p, c, maxPrice;
string name, maxName;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        cin >> p;
        maxPrice = 0;
        while(p--){
            cin >> c >> name;
            if(maxPrice < c){
                maxPrice = c;
                maxName = name;
            }
        }
        cout << maxName << "\n";
    }

    return 0;
}