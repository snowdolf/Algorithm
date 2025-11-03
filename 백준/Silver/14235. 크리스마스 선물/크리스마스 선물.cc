#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int> pq;

    while (n--)
    {
        int a;
        cin >> a;

        if (a == 0)
        {
            if (pq.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            while (a--)
            {
                int x;
                cin >> x;
                pq.push(x);
            }
        }
    }

    return 0;
}