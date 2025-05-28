#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[10], b[10], asum, bsum, cnt;
    asum = bsum = cnt = 0;

    for(int i = 0; i < 10; i++)cin >> a[i];
    for(int i = 0; i < 10; i++)cin >> b[i];

    for(int i = 0; i < 10; i++){
        if(a[i] > b[i])asum += 3, cnt = 1;
        else if(a[i] < b[i])bsum += 3, cnt = 2;
        else asum++, bsum++;
    }

    cout << asum << " " << bsum << "\n";

    if(asum > bsum)cout << "A";
    else if(asum < bsum)cout << "B";
    else if(cnt == 1) cout << "A";
    else if(cnt == 2) cout << "B";
    else cout << "D";

    return 0;
}