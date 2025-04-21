#include <iostream>

using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    if(str == "NLCS"){
        cout << "North London Collegiate School";
    }
    else if(str == "BHA"){
        cout << "Branksome Hall Asia";
    }
    else if(str == "KIS"){
        cout << "Korea International School";
    }
    else if(str == "SJA"){
        cout << "St. Johnsbury Academy";
    }

    return 0;
}