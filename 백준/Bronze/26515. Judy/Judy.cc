#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void printChar(int x)
{
    if ('a' <= x && x <= 'z')
    {
        cout << (char)x;
    }
    else if ('A' <= x && x <= 'Z')
    {
        cout << (char)(x + 32);
    }
    else
    {
        cout << "-";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    while(t--)
    {
        string str;
        getline(cin, str);

        istringstream ss(str);
        vector<int> v;
        int x;

        while (ss >> x) v.push_back(x);

        for (int i = 1; i < v.size(); i++) printChar(v[i]);
        printChar(v[0]);
        cout << "ay\n";
    }

    return 0;
}