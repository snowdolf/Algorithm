#include <iostream>
#include <cmath>

using namespace std;

int n, combination[15][15];

long long findDecreasingNumber(int digits, int nth, int maxDigit){
    if(digits == 1)return nth - 1;

    int digit = 0;
    for(digit = digits - 1; digit <= maxDigit; digit++){
        if(nth <= combination[digit + 1][digits]){
            nth -= combination[digit][digits];
            break;
        }
    }

    return digit * (long long)pow(10, digits - 1) + findDecreasingNumber(digits - 1, nth, maxDigit - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i <= 10; i++){
        combination[i][0] = 1;
        combination[i][i] = 1;
    }
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= i; j++){
            combination[i][j] = combination[i - 1][j] + combination[i - 1][j - 1];
        }
    }

    int sum = -1, digits = 0;
    for(int i = 1; i <= 10; i++){
        if(n <= (sum + combination[10][i])){
            n -= sum;
            digits = i;
            break;
        }
        sum += combination[10][i];
    }

    if(digits)cout << findDecreasingNumber(digits, n, 9);
    else cout << "-1";

    return 0;
}