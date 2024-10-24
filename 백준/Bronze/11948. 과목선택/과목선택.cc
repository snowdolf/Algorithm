#include <iostream>

using namespace std;

int score[10], sum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 6; i++){
        cin >> score[i];
        sum += score[i];
    }

    int cnt = 100;
    for(int i = 0; i < 4; i++)if(cnt > score[i])cnt = score[i];

    sum -= cnt;

    sum -= (score[4] < score[5] ? score[4] : score[5]);

    cout << sum;

    return 0;
}