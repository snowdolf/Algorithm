#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
int isPrime[1003002];

void initPrime()
{
    isPrime[1] = -1;
    for(int i = 2; i <= 1003001; i++){
        if(isPrime[i] == 0){
            isPrime[i] = 1;
            for(int j = 2 * i; j <= 1003001; j += i){
                isPrime[j] = -1;
            }
        }
    }
}

bool isPalindrome(int x){
    string str = to_string(x);

    string streverse = str;
    reverse(streverse.begin(), streverse.end());

    return str == streverse;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    initPrime();

    for(int i = 2;; i++){
        if(i >= n && isPrime[i] == 1 && isPalindrome(i)){
            cout << i;
            break;
        }
    }

    return 0;
}