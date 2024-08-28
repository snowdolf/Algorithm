#include <iostream>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;

ll n, l, r, ans;
stack<ll> st;
map<ll, ll> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cin >> l;
    if(mp.find(l) == mp.end()){
        mp.insert({l, 1});
    }
    else{
        mp[l]++;
    }
    st.push(l);

    for (int i = 1; i < n; i++)
    {
        cin >> r;
        while (!st.empty())
        {
            if (st.top() < r)
            {
                ans += mp[st.top()];
                mp[st.top()] = 0;
                st.pop();
            }
            else if(st.top() == r){
                st.pop();
            }
            else
            {
                l = st.top();
                break;
            }
        }
        if (!st.empty())
            ans++;

        if(mp.find(r) == mp.end()){
            mp.insert({r, 1});
        }
        else{
            mp[r]++;
        }
        st.push(r);

        ans = ans + mp[r] - 1;
        l = r;
    }

    cout << ans;

    return 0;
}