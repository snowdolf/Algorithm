#include <iostream>

using namespace std;

int a[105], b[105];
int n, m, p, q, r;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)a[i] = i;

    for(int i = 0; i < m; i++){
        cin >> p >> r >> q;
        for(int j = p; j <= r; j++)b[j] = a[j];
        for(int j = 0; j <= r - q; j++)a[p + j] = b[q + j];
        for(int j = 0; j < q - p; j++)a[p + r - q + 1 + j] = b[p + j];
    }

    for(int i = 1; i <= n; i++)cout << a[i] << " ";

    return 0;
}