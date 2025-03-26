#include <iostream>
#include <map>
#include <cmath>

using namespace std;

string str;
map<string, int> mp;
int n = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (getline(cin, str))
    {
        mp[str]++;
        n++;
    }

    // 소수점 4자리까지 출력
    cout.precision(4);
    cout << fixed;

    double divisor = 100.0 / n;
    for (const auto& [key, value] : mp)
    {
        // round 함수는 소수점 1자리에서 반올림
        // round(x * 10000) / 10000은 소수점 5자리에서 반올림
        cout << key << " " << round(value * divisor * 10000) / 10000 << "\n";
    }

    return 0;
}