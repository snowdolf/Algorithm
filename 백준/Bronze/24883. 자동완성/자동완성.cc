#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char ch;
    cin >> ch;

    if(ch == 'N' || ch == 'n') cout << "Naver D2";
    else cout << "Naver Whale";

    return 0;
}