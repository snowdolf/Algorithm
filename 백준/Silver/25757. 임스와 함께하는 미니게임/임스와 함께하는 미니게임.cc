#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    char mode;
    cin >> mode;

    unordered_set<string> players;
    int ans = 0, count = 0, tmp = 0;

    switch (mode)
    {
    case 'Y':
        count = 1;
        break;
    case 'F':
        count = 2;
        break;
    case 'O':
        count = 3;
        break;
    default:
        break;
    }

    while (n--)
    {
        string player;
        cin >> player;

        if (players.find(player) == players.end())
        {
            players.insert(player);
            tmp++;
        }
        if (tmp == count)
        {
            ans++;
            tmp = 0;
        }
    }

    cout << ans << "\n";

    return 0;
}