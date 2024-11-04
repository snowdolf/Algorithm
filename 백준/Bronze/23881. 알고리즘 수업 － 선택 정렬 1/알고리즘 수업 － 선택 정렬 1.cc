#include <iostream>

using namespace std;

int n, k, a, b;
int arr[10010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)cin >> arr[i];

    for(int i = n - 1; i >= 1; i--){
        int idx = i;
        for(int j = 0; j <= i; j++){
            if(arr[idx] < arr[j]){
                idx = j;
            }
        }
        if(idx != i){
            k--;
            arr[idx] ^= arr[i] ^= arr[idx] ^= arr[i];
            if(k == 0){
                a = arr[idx];
                b = arr[i];
            }
        }
    }

    if(k > 0)cout << "-1";
    else cout << a << " " << b;

    return 0;
}