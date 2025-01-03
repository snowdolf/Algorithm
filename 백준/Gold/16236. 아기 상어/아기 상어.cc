#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos {
    int x, y;
};

struct Shark {
    Pos pos;
    int size, eat;
};

int n, a[25][25], t = 0;
Shark shark;

bool cmp(const pair<Pos, int> &p, const pair<Pos, int> &q) {
    if (p.second != q.second) return p.second < q.second;
    if (p.first.x != q.first.x) return p.first.x < q.first.x;
    return p.first.y < q.first.y;
}

pair<Pos, int> findFish()
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<pair<Pos, int>> que;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    que.push({shark.pos, 0});
    visited[shark.pos.x][shark.pos.y] = true;

    vector<pair<Pos, int>> fish;

    while (!que.empty())
    {
        auto [pos, dist] = que.front();
        que.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            Pos npos = {pos.x + dx[dir], pos.y + dy[dir]};
            if (npos.x < 0 || npos.x >= n || npos.y < 0 || npos.y >= n) continue;
            if (visited[npos.x][npos.y] || a[npos.x][npos.y] > shark.size) continue;

            que.push({npos, dist + 1});
            visited[npos.x][npos.y] = true;

            if (a[npos.x][npos.y] > 0 && a[npos.x][npos.y] < shark.size) {
                fish.push_back({npos, dist + 1});
            }
        }
    }

    if (fish.empty()) return {{-1, -1}, 0};
    sort(fish.begin(), fish.end(), cmp);
    return fish[0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                shark = {{i, j}, 2, 0};
                a[i][j] = 0;
            }
        }
    }

    while (1) {
        auto [pos, dist] = findFish();

        if (dist == 0) break;

        a[pos.x][pos.y] = 0;
        shark.pos = pos;
        t += dist;

        shark.eat++;
        if (shark.eat == shark.size) {
            shark.size++;
            shark.eat = 0;
        }
    }

    cout << t;

    return 0;
}