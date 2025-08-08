#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int find(int x, vector<int> &root)
{
    if (root[x] == x) return x;
    return root[x] = find(root[x], root);
}

void unite(int x, int y, vector<int> &root, vector<int> &height, vector<int> &size)
{
    x = find(x, root);
    y = find(y, root);
    if (x == y) return;

    if (height[x] < height[y])
    {
        root[x] = y;
        size[y] += size[x];
    }
    else
    {
        root[y] = x;
        if (height[x] == height[y]) height[x]++;
        size[x] += size[y];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> root, height, size;
        unordered_map<string, int> map;
        int idx = 0;

        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;

            if (map.find(a) == map.end())
            {
                root.push_back(idx);
                height.push_back(1);
                size.push_back(1);
                map[a] = idx++;
            }
            if (map.find(b) == map.end())
            {
                root.push_back(idx);
                height.push_back(1);
                size.push_back(1);
                map[b] = idx++;
            }

            unite(map[a], map[b], root, height, size);
            cout << size[find(map[a], root)] << "\n";
        }
    }

    return 0;
}