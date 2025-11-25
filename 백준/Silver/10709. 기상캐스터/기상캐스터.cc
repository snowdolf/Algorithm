#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; i++)
    {
        bool noCloud = true;
        int tmp = 0;
        for (int j = 0; j < w; j++)
        {
            char c;
            cin >> c;

            bool isCloud = false;

            if (c == 'c') noCloud = false, isCloud = true, tmp = 0;
            else tmp++;

            if (noCloud) cout << "-1 ";
            else cout << tmp << " ";
        }
        cout << "\n";
    }

    return 0;
}