#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(string x)
{
    int ret = 0;

    for (auto i : x)
    {
        if ('0' <= i && i <= '9')
        {
            ret += (i - '0');
        }
    }

    return ret;
}

bool cmp(string x, string y)
{
    if (x.size() != y.size())
        return x.size() < y.size();
    else if (f(x) != f(y))
        return f(x) < f(y);
    else
        return x < y;
}

int n;
vector<string> vs;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vs.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vs[i];
    }

    sort(vs.begin(), vs.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << vs[i] << "\n";
    }

    return 0;
}