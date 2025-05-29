#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, grid[1001][1001], cp[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        for(int j = x; j < x + a; j++){
            for(int k = y; k < y + b; k++){
                cp[grid[j][k]]--;
                grid[j][k] = i;
                cp[grid[j][k]]++;
            }
        }
    }

    for(int i = 1; i <= n; i++)cout << cp[i] << '\n';

    return 0;
}