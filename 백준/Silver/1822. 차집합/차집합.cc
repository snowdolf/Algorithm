#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    set<int> sa;
    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        sa.insert(x);
    }

    for (int i = 0; i < b; i++)
    {
        int x;
        cin >> x;
        if (sa.find(x) != sa.end())
        {
            sa.erase(x);
        }
    }

    cout << sa.size() << "\n";
    for (auto &x : sa)
    {
        cout << x << " ";
    }

    return 0;
} 