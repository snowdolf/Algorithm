#include <iostream>

using namespace std;

int k, d, a;

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    scanf("%d/%d/%d", &k, &d, &a);

    if(k + a < d || d == 0)printf("hasu");
    else printf("gosu");

    return 0;
}