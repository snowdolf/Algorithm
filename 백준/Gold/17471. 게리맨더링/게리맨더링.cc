#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, p[15], q[15], a, b, ans = -1;
vector<int> adj[15];
bool visited[15];
queue<int> que;

void bfs(int start, int target, int& cnt, int& sum, int targetCount) {
    fill(begin(visited), end(visited), false);
    while (!que.empty()) que.pop();

    cnt = 0;
    sum = 0;

    que.push(start);
    visited[start] = true;
    cnt++;
    sum += p[start];

    while (!que.empty()) {
        int curr = que.front();
        que.pop();

        for (int neighbor : adj[curr]) {
            if (visited[neighbor] || q[neighbor] != target) continue;
            que.push(neighbor);
            visited[neighbor] = true;
            cnt++;
            sum += p[neighbor];
        }
    }
}

void calculateDifference(int x, int y) {
    int cnt1, sum1, cnt2, sum2;
    bfs(1, q[1], cnt1, sum1, x);

    int target2 = -q[1];
    int target2Index = 2;
    while (q[target2Index] != target2) target2Index++;
    bfs(target2Index, target2, cnt2, sum2, y);

    if (cnt1 == x && cnt2 == y) {
        int diff = abs(sum1 - sum2);
        if (ans < 0) ans = diff;
        else ans = min(ans, diff);
    }
}

void partition(int idx, int group1Count, int group2Count) {
    if (idx == n) {
        if (group1Count && group2Count) calculateDifference(group1Count, group2Count);
        return;
    }

    q[idx + 1] = 1;
    partition(idx + 1, group1Count + 1, group2Count);

    q[idx + 1] = -1;
    partition(idx + 1, group1Count, group2Count + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];

    for (int i = 1; i <= n; i++) {
        cin >> a;
        while (a--) {
            cin >> b;
            adj[i].push_back(b);
        }
    }

    q[1] = 1;
    partition(1, 1, 0);

    cout << ans;
    return 0;
}
