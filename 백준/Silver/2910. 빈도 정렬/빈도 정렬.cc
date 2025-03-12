#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
map<int, int> num, fidx;
vector<int> vec;

bool cmp(int x, int y)
{
    if (num[x] != num[y])
        return num[x] > num[y];
    return fidx[x] < fidx[y];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int cnt;
        cin >> cnt;

        num[cnt]++;

        if (!fidx.count(cnt))
        {
            fidx[cnt] = i;
        }

        vec.push_back(cnt);
    }

    sort(vec.begin(), vec.end(), cmp);

    for (auto i : vec)
        cout << i << " ";

    return 0;
}