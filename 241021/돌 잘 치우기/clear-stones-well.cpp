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
int n, k, m;
int main() {
    cin >> n >> k >> m;
    vector<pair<int, int>> stone;
    vector<pair<int, int>> start;
    vector<int> check;
    int res = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1)
                stone.push_back({ i,j });
        }
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        start.push_back({ x,y });

    }
    for (int i = 0; i < m; i++) {
        check.push_back(0);
    }
    for (int i = 0; i < stone.size() - m; i++) {
        check.push_back(1);
    }
    
    do {
        //temp board 생성
        int temp[109][109];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                temp[i][j] = board[i][j];
            }
        }

        for (int i = 0; i < check.size(); i++) {
            if (check[i] == 0) {
                //stone[i].first, second를 현재 돌에서 0으로 만든다
                temp[stone[i].first][stone[i].second] = 0;
            }
        }

        int temp_res = 0;
        int visit[109][109] = { 0, };
        for (int i = 0; i < k; i++) {
            queue<pair<int, int>>Q;
            if (visit[start[i].first][start[i].second] == 0) {
                Q.push({ start[i].first, start[i].second });
                visit[start[i].first][start[i].second] = 1;
                temp_res++;

                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
                        if (temp[nx][ny] == 0 && visit[nx][ny] == 0) {
                            Q.push({ nx, ny });
                            temp_res++;
                            visit[nx][ny] = 1;
                        }
                    }
                }
            }


        }
        res = max(res, temp_res);


    } while (next_permutation(check.begin(), check.end()));

    cout << res;



}