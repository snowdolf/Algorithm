#include <iostream>
#include <stack>

using namespace std;

string str, ans;
stack<char> st;

void f(){
    while(!st.empty()){
        char cnt = st.top();
        if(cnt == '(')return;
        st.pop();
        ans += cnt;
    }
}

void g(){
    while(!st.empty()){
        char cnt = st.top();
        if(cnt != '*' && cnt != '/')return;
        st.pop();
        ans += cnt;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    for(auto i : str){
        if('A' <= i && i <= 'Z'){
            ans += i;
        }
        else{
            if(i == ')'){
                f();
                st.pop();
            }
            if(i == '*' || i == '/'){
                g();
            }
            if(i == '+' || i == '-'){
                f();
            }
            if(i != ')'){
                st.push(i);
            }
        }
    }
    f();

    cout << ans;

    return 0;
}