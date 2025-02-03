#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s, p;
vector<int> score;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> p;

    score.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
    }
    score.push_back(s);

    sort(score.begin(), score.end(), greater<int>());

    int cnt1 = upper_bound(score.begin(), score.end(), s, greater<int>()) - score.begin();
    int cnt2 = lower_bound(score.begin(), score.end(), s, greater<int>()) - score.begin() + 1;

    cout << (cnt1 > p ? -1 : cnt2);

    return 0;
}