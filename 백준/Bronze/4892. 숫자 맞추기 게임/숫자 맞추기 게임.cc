#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    for(int i = 1;; i++){
        cin >> n;
        if(n == 0)break;

        cout << i << ". " << (n % 2 ? "odd " : "even ") << n / 2 << "\n";
    }

    return 0;
}