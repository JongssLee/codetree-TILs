#include <iostream>
#include <stack>
#include <utility>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int board[109][109] = { 0, };
int dp[1009][1009] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, k, u, d;
int main() {
    cin >> n >> k >> u >> d;
    vector<pair<int, int>> city;
    vector<pair<int, int>> start;
    vector<int> check;
    int res = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            city.push_back({ i, j });
        }
    }
    
    for (int i = 0; i < k; i++) {
        check.push_back(0);
    }
    for (int i = 0; i < n-k; i++) {
        check.push_back(1);
    }
    
    do {
        vector<pair<int, int>> start;
        int temp_res = 0;
        int visit[10][10] = { 0, };
        for (int i = 0; i < check.size(); i++) {
            if (check[i] == 0) {
                start.push_back(city[i]);
            }
        }
        for (int i = 0; i < k; i++) {
            auto start_city = start[i];
            queue<pair<int, int>>Q;
            if (visit[start_city.first][start_city.second] == 0) {
                Q.push(start_city);
                visit[start_city.first][start_city.second] = 1;
                temp_res++;

                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    int cur_h = board[cur.first][cur.second];
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        int diff = abs(cur_h - board[nx][ny]);
                        if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
                        if (visit[nx][ny] == 0) {
                            if (diff >= u && diff <= d) {
                                visit[nx][ny] = 1;
                                Q.push({ nx, ny });
                                temp_res++;
                            }
                        }
                    }
                }

            }
        }
        res = max(res, temp_res);



    } while (next_permutation(check.begin(), check.end()));

    cout << res;



}