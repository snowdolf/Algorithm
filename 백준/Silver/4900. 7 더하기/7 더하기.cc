#include <iostream>

using namespace std;

int code[10] = {63, 10, 93, 79, 106, 103, 119, 11, 127, 107};
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> str;
        if(str == "BYE") break;

        int a = 0, b = 0;
        bool isFirst = true;
        for(int i = 0; i < str.size() - 1; i++){
            int tmp = 0;
            if(str[i] != '+'){
                for(int j = 0; j < 3; j++) tmp = tmp * 10 + str[i + j] - '0';
                i += 2;
                for(int j = 0; j < 10; j++){
                    if(tmp == code[j]){
                        tmp = j;
                        break;
                    }
                }
                if(isFirst) a = a * 10 + tmp;
                else b = b * 10 + tmp;
            }
            else isFirst = false;
        }

        cout << str;
        string ans = to_string(a + b);
        for(int i = 0; i < ans.size(); i++){
            int tmp = ans[i] - '0';
            if(code[tmp] < 100) cout << "0";
            cout << code[tmp];
        }
        cout << "\n";
    }

    return 0;
}