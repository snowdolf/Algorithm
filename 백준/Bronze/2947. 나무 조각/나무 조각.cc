#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v(5);
    for(int i = 0; i < 5; i++)cin >> v[i];

    for(int i = 3; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
                for(int k = 0; k < 5; k++){
                    cout << v[k] << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}