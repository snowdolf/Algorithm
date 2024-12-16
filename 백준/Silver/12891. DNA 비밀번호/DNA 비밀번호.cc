#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s, p;
    cin >> s >> p;

    string str;
    cin >> str;

    int minA, minC, minG, minT;
    cin >> minA >> minC >> minG >> minT;

    int countA = 0, countC = 0, countG = 0, countT = 0, ans = 0;
    for(int i = 0; i < p; i++){
        if(str[i] == 'A')countA++;
        if(str[i] == 'C')countC++;
        if(str[i] == 'G')countG++;
        if(str[i] == 'T')countT++;
    }

    for(int i = 0; i <= s - p; i++){
        if(countA >= minA && countC >= minC && countG >= minG && countT >= minT){
            ans++;
        }

        if(i != s - p){
            if(str[i] == 'A')countA--;
            if(str[i] == 'C')countC--;
            if(str[i] == 'G')countG--;
            if(str[i] == 'T')countT--;

            if(str[i + p] == 'A')countA++;
            if(str[i + p] == 'C')countC++;
            if(str[i + p] == 'G')countG++;
            if(str[i + p] == 'T')countT++;
        }
    }

    cout << ans;

    return 0;
}