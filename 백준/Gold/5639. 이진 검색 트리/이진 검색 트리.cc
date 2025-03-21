#include <iostream>
#include <vector>

using namespace std;

int x;
vector<int> preOrder, postOrder;

void preToPost(int l, int r)
{
    if (l > r) return;
    if (l == r) {
        postOrder.push_back(preOrder[l]);
        return;
    }

    int idx = l + 1;
    while (idx <= r && preOrder[idx] < preOrder[l]) idx++;

    preToPost(l + 1, idx - 1);
    preToPost(idx, r);
    postOrder.push_back(preOrder[l]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> x) preOrder.push_back(x);

    preToPost(0, preOrder.size() - 1);
    
    for (int i : postOrder) cout << i << " ";

    return 0;
}