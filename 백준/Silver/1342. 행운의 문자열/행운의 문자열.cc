#include <iostream>
#include <vector>

using namespace std;

void dfs (vector<int>& cnt, int prev, int left, int* ans)
{
    if (left == 0)
    {
        (*ans)++;
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] == 0 || i == prev) continue;

        cnt[i]--;
        dfs(cnt, i, left - 1, ans);
        cnt[i]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;

    int ans = 0;
    dfs(cnt, -1, s.size(), &ans);
    cout << ans << "\n";

    return 0;
}