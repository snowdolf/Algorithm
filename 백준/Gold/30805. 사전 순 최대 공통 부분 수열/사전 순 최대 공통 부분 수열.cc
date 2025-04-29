#include <iostream>

using namespace std;

int n, m, a[105], b[105], aidx, bidx, c[105], k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i];

    while(aidx < n && bidx < m) {
        int ax = aidx, bx = bidx, maxnum = 0;
        for(int i = aidx; i < n; i++){
            for(int j = bidx; j < m; j++){
                if(a[i] == b[j] && a[i] > maxnum){
                    maxnum = a[i];
                    ax = i;
                    bx = j;
                }
            }
        }

        if(maxnum == 0) break;
        c[k++] = maxnum;
        aidx = ax + 1;
        bidx = bx + 1;
    }

    cout << k << "\n";
    for(int i = 0; i < k; i++) cout << c[i] << " ";

    return 0;
}