#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> map_before(r + 2, vector<char>(c + 2, '.'));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> map_before[i][j];
        }
    }

    vector<vector<char>> map_after(r + 2, vector<char>(c + 2, '.'));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            map_after[i][j] = map_before[i][j];
            if (map_before[i][j] == 'X')
            {
                int cnt = 0;
                if (map_before[i - 1][j] == '.') cnt++;
                if (map_before[i + 1][j] == '.') cnt++;
                if (map_before[i][j - 1] == '.') cnt++;
                if (map_before[i][j + 1] == '.') cnt++;

                if (cnt >= 3) map_after[i][j] = '.';
            }
        }
    }

    int min_r = 1, max_r = r, min_c = 1, max_c = c;
    for (int i = 1; i <= r; i++)
    {
        bool chk = false;
        for (int j = 1; j <= c; j++)
        {
            if (map_after[i][j] == 'X')
            {
                chk = true;
                break;
            }
        }
        if (chk)
        {
            min_r = i;
            break;
        }
    }
    for (int i = r; i >= 1; i--)
    {
        bool chk = false;
        for (int j = 1; j <= c; j++)
        {
            if (map_after[i][j] == 'X')
            {
                chk = true;
                break;
            }
        }
        if (chk)
        {
            max_r = i;
            break;
        }
    }
    for (int j = 1; j <= c; j++)
    {
        bool chk = false;
        for (int i = 1; i <= r; i++)
        {
            if (map_after[i][j] == 'X')
            {
                chk = true;
                break;
            }
        }
        if (chk)
        {
            min_c = j;
            break;
        }
    }
    for (int j = c; j >= 1; j--)
    {
        bool chk = false;
        for (int i = 1; i <= r; i++)
        {
            if (map_after[i][j] == 'X')
            {
                chk = true;
                break;
            }
        }
        if (chk)
        {
            max_c = j;
            break;
        }
    }

    for (int i = min_r; i <= max_r; i++)
    {
        for (int j = min_c; j <= max_c; j++)
        {
            cout << map_after[i][j];
        }
        cout << "\n";
    }

    return 0;
}