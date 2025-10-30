#include <iostream>
#include <vector>

using namespace std;

int energy(vector<int> w)
{
    if (w.size() == 2) return 0;

    int ret = 0;
    for (int i = 1; i < w.size() - 1; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < w.size(); j++)
        {
            if (j != i) tmp.push_back(w[j]);
        }
        ret = max(ret, energy(tmp) + w[i - 1] * w[i + 1]);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> w(n);
    for (auto &x : w) cin >> x;

    cout << energy(w);

    return 0;
}