#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, arr[505][505];
int ans, cnt;

vector<vector<pair<int, int>>> v14;
vector<vector<pair<int, int>>> v22;
vector<vector<pair<int, int>>> v23;
vector<vector<pair<int, int>>> v32;
vector<vector<pair<int, int>>> v41;

void f14(int x, int y){
    for(auto i : v14){
        cnt = 0;
        for(auto j : i){
            cnt += arr[x + j.first][y + j.second];
        }
        ans = max(ans, cnt);
    }
}
void f22(int x, int y){
    for(auto i : v22){
        cnt = 0;
        for(auto j : i){
            cnt += arr[x + j.first][y + j.second];
        }
        ans = max(ans, cnt);
    }
}
void f23(int x, int y){
    for(auto i : v23){
        cnt = 0;
        for(auto j : i){
            cnt += arr[x + j.first][y + j.second];
        }
        ans = max(ans, cnt);
    }
}
void f32(int x, int y){
    for(auto i : v32){
        cnt = 0;
        for(auto j : i){
            cnt += arr[x + j.first][y + j.second];
        }
        ans = max(ans, cnt);
    }
}
void f41(int x, int y){
    for(auto i : v41){
        cnt = 0;
        for(auto j : i){
            cnt += arr[x + j.first][y + j.second];
        }
        ans = max(ans, cnt);
    }
}

void setVector(){
    vector<pair<int, int>> v;

    // blue
    v.clear();
    v.push_back({0, 0});v.push_back({0, 1});v.push_back({0, 2});v.push_back({0, 3});
    v14.push_back(v);

    v.clear();
    v.push_back({0, 0});v.push_back({1, 0});v.push_back({2, 0});v.push_back({3, 0});
    v41.push_back(v);

    // yellow
    v.clear();
    v.push_back({0, 0});v.push_back({0, 1});v.push_back({1, 0});v.push_back({1, 1});
    v22.push_back(v);

    // orange
    v.clear();
    v.push_back({0, 0});v.push_back({0, 1});v.push_back({0, 2});v.push_back({1, 0});
    v23.push_back(v);

    v.clear();
    v.push_back({0, 0});v.push_back({0, 1});v.push_back({0, 2});v.push_back({1, 2});
    v23.push_back(v);

    v.clear();
    v.push_back({0, 0});v.push_back({1, 0});v.push_back({1, 1});v.push_back({1, 2});
    v23.push_back(v);

    v.clear();
    v.push_back({0, 2});v.push_back({1, 0});v.push_back({1, 1});v.push_back({1, 2});
    v23.push_back(v);

    v.clear();
    v.push_back({0, 0});v.push_back({0, 1});v.push_back({1, 0});v.push_back({2, 0});
    v32.push_back(v);

    v.clear();
    v.push_back({0, 0});v.push_back({0, 1});v.push_back({1, 1});v.push_back({2, 1});
    v32.push_back(v);

    v.clear();
    v.push_back({0, 0});v.push_back({1, 0});v.push_back({2, 0});v.push_back({2, 1});
    v32.push_back(v);

    v.clear();
    v.push_back({0, 1});v.push_back({1, 1});v.push_back({2, 0});v.push_back({2, 1});
    v32.push_back(v);

    // green
    v.clear();
    v.push_back({0, 0});v.push_back({0, 1});v.push_back({1, 1});v.push_back({1, 2});
    v23.push_back(v);

    v.clear();
    v.push_back({0, 1});v.push_back({0, 2});v.push_back({1, 0});v.push_back({1, 1});
    v23.push_back(v);

    v.clear();
    v.push_back({0, 0});v.push_back({1, 0});v.push_back({1, 1});v.push_back({2, 1});
    v32.push_back(v);

    v.clear();
    v.push_back({0, 1});v.push_back({1, 1});v.push_back({1, 0});v.push_back({2, 0});
    v32.push_back(v);

    // pink
    v.clear();
    v.push_back({0, 0});v.push_back({0, 1});v.push_back({0, 2});v.push_back({1, 1});
    v23.push_back(v);

    v.clear();
    v.push_back({0, 1});v.push_back({1, 0});v.push_back({1, 1});v.push_back({1, 2});
    v23.push_back(v);

    v.clear();
    v.push_back({0, 0});v.push_back({1, 0});v.push_back({1, 1});v.push_back({2, 0});
    v32.push_back(v);

    v.clear();
    v.push_back({0, 1});v.push_back({1, 0});v.push_back({1, 1});v.push_back({2, 1});
    v32.push_back(v);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)cin >> arr[i][j];

    setVector();

    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++){
        if(j + 3 < m){
            f14(i, j);
        }
        if(i + 1 < n && j + 1 < m){
            f22(i, j);
        }
        if(i + 1 < n && j + 2 < m){
            f23(i, j);
        }
        if(i + 2 < n && j + 1 < m){
            f32(i, j);
        }
        if(i + 3 < n){
            f41(i, j);
        }
    }

    cout << ans;

    return 0;
}