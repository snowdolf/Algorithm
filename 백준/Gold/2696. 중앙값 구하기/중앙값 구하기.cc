#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int m;
        cin >> m;
        cout << (m + 1) / 2 << "\n";

        priority_queue<int> lq;
        int mid;
        priority_queue<int, vector<int>, greater<int>> rq;

        for (int i = 1; i <= m; i++)
        {
            int n;
            cin >> n;

            if (i == 1) mid = n;
            else if (mid > n) lq.push(n);
            else rq.push(n);

            if (i % 2)
            {
                if (lq.size() > rq.size())
                {
                    rq.push(mid);
                    mid = lq.top();
                    lq.pop();
                }
                else if (rq.size() > lq.size())
                {
                    lq.push(mid);
                    mid = rq.top();
                    rq.pop();
                }
                cout << mid << " ";
            }
            if (i != 1 && i % 20 == 0 && i != m) cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}