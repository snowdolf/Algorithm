#include <iostream>

using namespace std;

int t, n;
bool isClosed[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++)isClosed[i] = true;
        for(int i = 1; i <= n; i++)for(int j = i; j <= n; j += i)isClosed[j] = !isClosed[j];
        int cnt = 0;
        for(int i = 1; i <= n; i++)if(!isClosed[i])cnt++;
        cout << cnt << "\n";
    }

    return 0;
}