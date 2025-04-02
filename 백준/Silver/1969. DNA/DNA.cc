#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[55], t[55], g[55], c[55], sum;
string ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            if(str[j] == 'A')a[j]++;
            else if(str[j] == 'T')t[j]++;
            else if(str[j] == 'G')g[j]++;
            else if(str[j] == 'C')c[j]++;
        }
    }

    for(int i = 0; i < m; i++){
        int maxCount = max({a[i], t[i], g[i], c[i]});
        if(maxCount == a[i])ans += 'A';
        else if(maxCount == c[i])ans += 'C';
        else if(maxCount == g[i])ans += 'G';
        else if(maxCount == t[i])ans += 'T';
        sum += (n - maxCount);
    }

    cout << ans << "\n" << sum;

    return 0;
}