#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_N = 1003001;

int n;
bool isPrime[MAX_N + 1];

void initPrime()
{
    fill(isPrime, isPrime + MAX_N + 1, 1);

    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= MAX_N; i++)
    {
        if (isPrime[i])
        {
            for (long long j = i * i; j <= MAX_N; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}

bool isPalindrome(int x)
{
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

    for (int i = n;; i++)
    {
        if (isPrime[i] == 1 && isPalindrome(i))
        {
            cout << i;
            break;
        }
    }

    return 0;
}