#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        string x, y;
        cin >> x >> y;

        cout << "Distances: ";
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] <= y[i]) cout << y[i] - x[i] << " ";
            else cout << y[i] - x[i] + 26 << " ";
        }
        cout << "\n";
    }

    return 0;
}