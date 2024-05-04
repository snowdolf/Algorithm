#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int n;

void f()
{
    string str;
    getline(cin, str);

    istringstream ss(str);
    string stringBuffer;
    vector<string> v;
    v.clear();
    
    while(getline(ss, stringBuffer, ' ')){
        v.push_back(stringBuffer);
    }

    double ans = stod(v[0]);
    for(int i = 1; i < v.size(); i++){
        if(v[i] == "@"){
            ans *= 3;
        }
        if(v[i] == "%"){
            ans += 5;
        }
        if(v[i] == "#"){
            ans -= 7;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin.ignore();

    cout.precision(2);
    cout << fixed;

    while(n--){
        f();
    }

    return 0;
}