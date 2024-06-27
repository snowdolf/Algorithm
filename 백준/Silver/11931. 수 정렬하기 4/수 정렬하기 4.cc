#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int x, int y)
{
    return x > y;
}

int n, arr[1000010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";

    return 0;
}