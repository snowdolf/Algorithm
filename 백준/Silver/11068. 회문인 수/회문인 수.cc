#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        bool isHM = false;

        for (int i = 2; i <= 64; i++)
        {
            vector<int> v;

            int m = n;
            while (m)
            {
                v.push_back(m % i);
                m /= i;
            }

            bool cnt = true;
            for (int j = 0; j < v.size() / 2; j++)
            {
                if (v[j] != v[v.size() - 1 - j])
                {
                    cnt = false;
                    break;
                }
            }
            if (cnt)
            {
                isHM = true;
                break;
            }
        }

        if (isHM) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}