#include <iostream>

using namespace std;

char ch;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> ch;
    if(ch == 'M')cout << "MatKor";
    if(ch == 'W')cout << "WiCys";
    if(ch == 'C')cout << "CyKor";
    if(ch == 'A')cout << "AlKor";
    if(ch == '$')cout << "$clear";

    return 0;
}