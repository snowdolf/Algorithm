#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string Add(string p, string q){
    string res;
    int sum = 0;

    reverse(p.begin(), p.end());
    reverse(q.begin(), q.end());

    while(p.length() < q.length())p += '0';
    while(p.length() > q.length())q += '0';

    for(int i = 0; i < p.length(); i++){
        sum += p[i] - '0' + q[i] - '0';
        res += to_string(sum % 10);
        sum /= 10;
    }
    if(sum)res += to_string(sum);

    reverse(res.begin(), res.end());

    return res;
}

int n;
string x, y, z;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    y = "0";
    if(n)y = "1";

    for (int i = 2; i <= n; i++)
    {
        z = Add(x, y);
        x = y;
        y = z;
    }

    cout << y;

    return 0;
}
