#include <iostream>
#include <vector>
#include <set>

using namespace std;

void selectCard(int m, int k, string x, vector<int> &v, set<string> &s, vector<bool> &selected)
{
    if (m == k)
    {
        s.insert(x);
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (!selected[i])
        {
            selected[i] = true;

            string tmp = x + to_string(v[i]);
            selectCard(m + 1, k, tmp, v, s, selected);

            selected[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto &x : v) cin >> x;

    set<string> s;
    vector<bool> selected(n, false);

    selectCard(0, k, "", v, s, selected);

    cout << s.size();

    return 0;
}