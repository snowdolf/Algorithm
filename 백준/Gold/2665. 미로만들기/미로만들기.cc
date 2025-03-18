#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

const int INF = 10000;
int n, room[55][55], ans;

vector<P> edge[2505];
int d[2505], past[2505];
vector<int> path;

priority_queue<P, vector<P>, greater<P>> que;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            room[i][j] = str[j] - '0';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(room[i][j + 1])edge[i * n + j].push_back(P(i * n + j + 1, 1));
            else edge[i * n + j].push_back(P(i * n + j + 1, INF));

            if(room[i][j])edge[i * n + j + 1].push_back(P(i * n + j, 1));
            else edge[i * n + j + 1].push_back(P(i * n + j, INF));
        }
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n; j++){
            if(room[i + 1][j])edge[i * n + j].push_back(P((i + 1) * n + j, 1));
            else edge[i * n + j].push_back(P((i + 1) * n + j, INF));

            if(room[i][j])edge[(i + 1) * n + j].push_back(P(i * n + j, 1));
            else edge[(i + 1) * n + j].push_back(P(i * n + j, INF));
        }
    }

    for(int i = 0; i < n * n; i++)d[i] = 100 * INF;
    for(int i = 0; i < n * n; i++)past[i] = -1;
    d[0] = 0;
    que.push(P(0, 0));

    while(!que.empty()){
        P p = que.top();
        que.pop();

        if(d[p.second] < p.first)continue;
        for(auto i : edge[p.second]){
            if(d[i.first] > d[p.second] + i.second){
                d[i.first] = d[p.second] + i.second;
                que.push(P(d[i.first], i.first));
                past[i.first] = p.second;
            }
        }
    }

    for(int i = n * n - 1; i != -1; i = past[i])path.push_back(i);
    for(auto i : path)if(!room[i / n][i % n])ans++;
    cout << ans;

    return 0;
}