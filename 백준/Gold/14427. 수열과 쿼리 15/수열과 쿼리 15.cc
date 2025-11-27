#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pq.push({a[i], i});
    }

    int m;
    cin >> m;

    while (m--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y, z;
            cin >> y >> z;
            a[y] = z;
            pq.push({z, y});
        }
        else
        {
            while (a[pq.top().second] != pq.top().first)
            {
                pq.pop();
            }
            cout << pq.top().second << "\n";
        }
    }

    return 0;
}