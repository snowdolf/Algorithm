#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> w, k;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; i++)
    {
        int cnt;
        cin >> cnt;
        w.push_back(cnt);
    }
    for (int i = 0; i < 10; i++)
    {
        int cnt;
        cin >> cnt;
        k.push_back(cnt);
    }

    sort(w.begin(), w.end(), cmp);
    sort(k.begin(), k.end(), cmp);

    cout << w[0] + w[1] + w[2] << " ";
    cout << k[0] + k[1] + k[2];

    return 0;
}