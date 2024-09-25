#include <iostream>
#include <map>

using namespace std;

int sum = 0, mode = 0, count = 0, n;
map<int, int> m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; i++)
    {
        cin >> n;

        sum += n;

        m[n]++;
    }

    for (auto i : m)
    {
        if (count < i.second)
        {
            mode = i.first;
            count = i.second;
        }
    }

    cout << sum / 10 << "\n"
         << mode;

    return 0;
}