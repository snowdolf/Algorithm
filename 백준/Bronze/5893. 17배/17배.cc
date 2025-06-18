#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    vector<int> n;

    cin >> s;
    for (char c : s) n.push_back(c - '0');
    for (int i = 0; i < 4; i++) n.push_back(0);

    for (int i = 0; i < s.size(); i++) n[i + 4] += (s[i] - '0');

    for (int i = n.size() - 1; i > 0; i--)
    {
        if (n[i] > 1)
        {
            n[i] -= 2;
            n[i - 1]++;
        }
    }
    if (n[0] > 1)
    {
        n[0] = 10;
    }

    for (auto i : n) cout << i;

    return 0;
}