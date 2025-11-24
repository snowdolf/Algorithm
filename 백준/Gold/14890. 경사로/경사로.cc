#include <iostream>
#include <vector>

using namespace std;

int f(const vector<vector<int>> &vec, int n, int l, int th)
{
    int ret = 0;

    bool chk = true;
    
    vector<bool> used(n, false);
    for (int i = 0; i < n - 1; i++)
    {
        if (vec[i + 1][th] == vec[i][th]) continue;
        else if (vec[i + 1][th] == vec[i][th] - 1)
        {
            bool chk2 = true;
            for (int j = i + 1; j <= i + l; j++)
            {
                if (j == n)
                {
                    chk2 = false;
                    break;
                }
                if (used[j])
                {
                    chk2 = false;
                    break;
                }
                if (vec[j][th] != vec[i + 1][th])
                {
                    chk2 = false;
                    break;
                }
                used[j] = true;
            }

            if (!chk2) chk = false;
            else i += l - 1;
        }
        else if (vec[i + 1][th] == vec[i][th] + 1)
        {
            bool chk2 = true;
            for (int j = i; j > i - l; j--)
            {
                if (j < 0)
                {
                    chk2 = false;
                    break;
                }
                if (used[j])
                {
                    chk2 = false;
                    break;
                }
                if (vec[j][th] != vec[i][th])
                {
                    chk2 = false;
                    break;
                }
                used[j] = true;
            }

            if (!chk2) chk = false;
        }
        else chk = false;

        if (!chk) break;
    }

    if (chk) ret++;

    chk = true;

    used.assign(n, false);
    for (int i = 0; i < n - 1; i++)
    {
        if (vec[th][i + 1] == vec[th][i]) continue;
        else if (vec[th][i + 1] == vec[th][i] - 1)
        {
            bool chk2 = true;
            for (int j = i + 1; j <= i + l; j++)
            {
                if (j == n)
                {
                    chk2 = false;
                    break;
                }
                if (used[j])
                {
                    chk2 = false;
                    break;
                }
                if (vec[th][j] != vec[th][i + 1])
                {
                    chk2 = false;
                    break;
                }
                used[j] = true;
            }

            if (!chk2) chk = false;
            else i += l - 1;
        }
        else if (vec[th][i + 1] == vec[th][i] + 1)
        {
            bool chk2 = true;
            for (int j = i; j > i - l; j--)
            {
                if (j < 0)
                {
                    chk2 = false;
                    break;
                }
                if (used[j])
                {
                    chk2 = false;
                    break;
                }
                if (vec[th][j] != vec[th][i])
                {
                    chk2 = false;
                    break;
                }
                used[j] = true;
            }

            if (!chk2) chk = false;
        }
        else chk = false;

        if (!chk) break;
    }

    if (chk) ret++;

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    vector<vector<int>> vec(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> vec[i][j];

    int ans = 0;

    for (int i = 0; i < n; i++) ans += f(vec, n, l, i);

    cout << ans << "\n";

    return 0;
}