#include <iostream>
#include <vector>

using namespace std;

int k, area;
vector<pair<int, int>> pos;

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    int x = 0, y = 0;
    for(int i = 0; i < 6; i++){
        int a, b;
        cin >> a >> b;
        x += dx[a] * b;
        y += dy[a] * b;
        pos.push_back({x, y});
    }

    for(int i = 0; i < 5; i++){
        area += pos[i].first * pos[i + 1].second - pos[i].second * pos[i + 1].first;
    }
    area += pos[5].first * pos[0].second - pos[5].second * pos[0].first;

    area = abs(area) / 2;

    cout << area * k;

    return 0;
}