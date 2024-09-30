#include <iostream>
#include <queue>

using namespace std;

int n, k, ans, ord[105];
queue<int> usage[105];
bool isPluggedIn[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        cin >> ord[i];
        usage[ord[i]].push(i);
    }

    for (int i = 1, count = 0; i <= k; i++)
    {
        if (count < n)
        {
            if (!isPluggedIn[ord[i]])
                count++;
        }
        else if (!isPluggedIn[ord[i]])
        {
            int unplugIdx, lateIdx = 0;
            for (int j = 1; j <= k; j++)
            {
                if (!isPluggedIn[ord[j]])
                    continue;

                if (usage[ord[j]].empty())
                {
                    unplugIdx = j;
                    break;
                }
                else if (usage[ord[j]].front() > lateIdx)
                {
                    unplugIdx = j;
                    lateIdx = usage[ord[j]].front();
                }
            }
            isPluggedIn[ord[unplugIdx]] = false;
            ans++;
        }
        isPluggedIn[ord[i]] = true;
        usage[ord[i]].pop();
    }

    cout << ans;

    return 0;
}