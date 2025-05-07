#include <iostream>

using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    if(str == "SONGDO") cout << "HIGHSCHOOL";
    else if(str == "CODE") cout << "MASTER";
    else if(str == "2023") cout << "0611";
    else if(str == "ALGORITHM") cout << "CONTEST";

    return 0;
}