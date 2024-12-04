#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n, ans;
vector<pair<int, int>> vec;
stack<pair<int, int>> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vec.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());

    st.push(vec[0]);
    for (int i = 1; i < n; i++)
    {
        pair<int, int> p = st.top();

        while (!st.empty() && st.top().second < vec[i].second)
        {
            p = st.top();
            st.pop();
        }

        if (st.empty())
        {
            ans += (vec[i].first - p.first) * p.second;
        }

        st.push(vec[i]);
    }

    while (!st.empty())
    {
        pair<int, int> p = st.top();
        st.pop();

        if (!st.empty())
        {
            ans += (p.first - st.top().first) * p.second;
        }
        else
        {
            ans += p.second;
        }
    }

    cout << ans;

    return 0;
}