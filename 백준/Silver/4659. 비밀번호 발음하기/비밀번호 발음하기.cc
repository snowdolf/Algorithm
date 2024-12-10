#include <iostream>

using namespace std;

bool isVowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool chk1(const string& str){
    for(auto ch : str){
        if(isVowel(ch)){
            return true;
        }
    }

    return false;
}

bool chk2(const string& str){
    if(str.length() < 3)return true;

    for(int i = 0; i < str.size() - 2; i++){
        if(isVowel(str[i]) == isVowel(str[i + 1]) && isVowel(str[i + 1]) == isVowel(str[i + 2])){
            return false;
        }
    }

    return true;
}

bool chk3(const string& str){
    if(str.length() < 2)return true;

    for(int i = 0; i < str.length() - 1; i++){
        if(str[i] != 'e' && str[i] != 'o' && str[i] == str[i + 1]){
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        string str;
        cin >> str;

        if(str == "end")break;

        bool isAcceptable = chk1(str) && chk2(str) && chk3(str);

        cout << "<" << str << "> is " << (isAcceptable ? "" : "not ") << "acceptable.\n";
    }

    return 0;
}