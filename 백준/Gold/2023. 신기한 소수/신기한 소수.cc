#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void backTrack(int x, int n)
{
    if (x >= (int)pow(10, n - 1) && x < (int)pow(10, n))
    {
        cout << x << "\n";
        return;
    }
    for (int y : {1, 3, 5, 7, 9})
    {
        int nx = x * 10 + y;
        if (isPrime(nx))
        {
            backTrack(nx, n);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int x : {2, 3, 5, 7})
    {
        backTrack(x, n);
    }

    return 0;
}