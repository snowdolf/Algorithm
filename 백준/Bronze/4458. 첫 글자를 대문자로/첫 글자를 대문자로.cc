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
    while(n--){
        getline(cin, str);
        if(str[0] > 'Z')str[0] -= ('a' - 'A');
        cout << str << "\n";
    }

    return 0;
}