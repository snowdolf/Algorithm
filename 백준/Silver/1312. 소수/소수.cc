#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, n;
    cin >> a >> b >> n;

    vector<int> vec;
    vector<int> remainderPos(b, -1);

    a %= b;

    int startIdx, len;
    while (true)
    {
        if (remainderPos[a] != -1)
        {
            startIdx = remainderPos[a];
            len = vec.size() - startIdx;
            break;
        }
        
        remainderPos[a] = vec.size();

        int p = (a * 10) / b;
        a = (a * 10) % b;

        vec.push_back(p);
    }

    if (n <= vec.size())
    {
        cout << vec[n - 1];
    }
    else
    {
        cout << vec[startIdx + (n - 1 - startIdx) % len];
    }

    return 0;
}