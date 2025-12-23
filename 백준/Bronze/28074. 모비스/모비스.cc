#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> count(26, 0);
    for (char c : s) count[c - 'A']++;

    int tmp = 0;
    if (count['M' - 'A']) tmp++;
    if (count['O' - 'A']) tmp++;
    if (count['B' - 'A']) tmp++;
    if (count['I' - 'A']) tmp++;
    if (count['S' - 'A']) tmp++;

    if (tmp == 5) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}