#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string k, s;
    int n;
    cin >> k >> s >> n;

    while (n--)
    {
        string t;
        cin >> t;

        string nk = k, ns = s;
        
        if (t == "R")
        {
            nk[0]++;
            if (nk[0] > 'H')
            {
                nk[0]--;
            }
            else if (nk == ns)
            {
                ns[0]++;
                if (ns[0] > 'H')
                {
                    ns[0]--;
                    nk[0]--;
                }
            }
        }
        else if (t == "L")
        {
            nk[0]--;
            if (nk[0] < 'A')
            {
                nk[0]++;
            }
            else if (nk == ns)
            {
                ns[0]--;
                if (ns[0] < 'A')
                {
                    ns[0]++;
                    nk[0]++;
                }
            }
        }
        else if (t == "B")
        {
            nk[1]--;
            if (nk[1] < '1')
            {
                nk[1]++;
            }
            else if (nk == ns)
            {
                ns[1]--;
                if (ns[1] < '1')
                {
                    ns[1]++;
                    nk[1]++;
                }
            }
        }
        else if (t == "T")
        {
            nk[1]++;
            if (nk[1] > '8')
            {
                nk[1]--;
            }
            else if (nk == ns)
            {
                ns[1]++;
                if (ns[1] > '8')
                {
                    ns[1]--;
                    nk[1]--;
                }
            }
        }
        else if (t == "RT")
        {
            nk[0]++;
            nk[1]++;
            if (nk[0] > 'H' || nk[1] > '8')
            {
                nk[0]--;
                nk[1]--;
            }
            else if (nk == ns)
            {
                ns[0]++;
                ns[1]++;
                if (ns[0] > 'H' || ns[1] > '8')
                {
                    ns[0]--;
                    ns[1]--;
                    nk[0]--;
                    nk[1]--;
                }
            }
        }
        else if (t == "LT")
        {
            nk[0]--;
            nk[1]++;
            if (nk[0] < 'A' || nk[1] > '8')
            {
                nk[0]++;
                nk[1]--;
            }
            else if (nk == ns)
            {
                ns[0]--;
                ns[1]++;
                if (ns[0] < 'A' || ns[1] > '8')
                {
                    ns[0]++;
                    ns[1]--;
                    nk[0]++;
                    nk[1]--;
                }
            }
        }
        else if (t == "RB")
        {
            nk[0]++;
            nk[1]--;
            if (nk[0] > 'H' || nk[1] < '1')
            {
                nk[0]--;
                nk[1]++;
            }
            else if (nk == ns)
            {
                ns[0]++;
                ns[1]--;
                if (ns[0] > 'H' || ns[1] < '1')
                {
                    ns[0]--;
                    ns[1]++;
                    nk[0]--;
                    nk[1]++;
                }
            }
        }
        else if (t == "LB")
        {
            nk[0]--;
            nk[1]--;
            if (nk[0] < 'A' || nk[1] < '1')
            {
                nk[0]++;
                nk[1]++;
            }
            else if (nk == ns)
            {
                ns[0]--;
                ns[1]--;
                if (ns[0] < 'A' || ns[1] < '1')
                {
                    ns[0]++;
                    ns[1]++;
                    nk[0]++;
                    nk[1]++;
                }
            }
        }

        k = nk;
        s = ns;
    }

    cout << k << '\n' << s << '\n';

    return 0;
}