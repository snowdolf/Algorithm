#include <iostream>

using namespace std;

string s, p;
bool isSubstring = false;
int kmp[1000010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> p;

    int a, b;
    for(a = 1, b = 0; a < p.size(); a++){
        while(b && p[a] != p[b])b = kmp[b - 1];
        if(p[a] == p[b])kmp[a] = ++b;
    }
    for(a = 0, b = 0; a < s.size(); a++){
        while(b && s[a] != p[b])b = kmp[b - 1];
        if(s[a] == p[b])b++;
        if(b == p.size()){
            isSubstring = true;
            break;
        }
    }

    cout << isSubstring ? 1 : 0;

    return 0;
}