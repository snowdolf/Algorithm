#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

bool isPrime[10000];
vector<int> adjacentNum[10000];

void generatePrimes(){
    fill(isPrime + 2, isPrime + 10000, true);

    for(int i = 2; i < 10000; i++){
        if(isPrime[i]){
            for(int j = 2 * i; j < 10000; j += i){
                isPrime[j] = false;
            }
        }
    }

    return;
}

void generateAdjacentNumbers(){
    for(int i = 1001; i < 10000; i += 2){
        if(isPrime[i]){
            for(int pos = 0; pos < 4; pos++){
                for(int digit = 0; digit < 10; digit++){
                    int x = (int)pow(10, pos + 1);
                    int y = (int)pow(10, pos);
                    int cnt = (i / x) * x + digit * y + i % y;

                    if(cnt >= 1000 && isPrime[cnt]){
                        adjacentNum[i].push_back(cnt);
                    }
                }
            }
        }
    }

    return;
}

int shortestPath(int start, int end){
    vector<bool> visited(10000, false);
    queue<pair<int, int>> que;

    que.push({start, 0});
    visited[start] = true;

    while(!que.empty()){
        auto [current, distance] = que.front();
        que.pop();

        if(current == end)return distance;

        for(auto next : adjacentNum[current]){
            if(!visited[next]){
                que.push({next, distance + 1});
                visited[next] = true;
            }
        }
    }

    return -1;
}

void init(){
    generatePrimes();
    generateAdjacentNumbers();
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int ans = shortestPath(a, b);

        if(ans < 0)cout << "Impossible\n";
        else cout << ans << "\n";
    }

    return 0;
}