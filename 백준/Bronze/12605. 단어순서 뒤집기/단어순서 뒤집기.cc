#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++)
    {
        string str;
        getline(cin, str);

        vector<string> vec;
        string w;

        for (char c : str)
        {
            if (c == ' ')
            {
                vec.push_back(w);
                w.clear();
            }
            else
            {
                w += c;
            }
        }
        vec.push_back(w);

        reverse(vec.begin(), vec.end());

        cout << "Case #" << i << ": ";
        for (string w : vec)
        {
            cout << w << " ";
        }
        cout << "\n";
    }

    return 0;
}