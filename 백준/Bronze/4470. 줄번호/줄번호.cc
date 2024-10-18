#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n; i++){
        getline(cin, str);
        cout << i << ". " << str << "\n";
    }

    return 0;
}