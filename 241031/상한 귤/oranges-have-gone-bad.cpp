#include <iostream>
#include <stack>
#include <utility>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int board[109][109] = { 0, };

int n, k;
vector<pair<int, int>> gyul;
int virus[109][109] = { 0, };
int ans[109][109] = { 0, };
int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                gyul.push_back({ i,j });
            }
            else if (board[i][j] == 2) {
                virus[i][j] = 1;
            }
            else if (board[i][j] == 0) {
                ans[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < gyul.size(); i++) {
        bool flag = false;
        int visited[109][109] = { 0, };
        queue<pair<pair<int, int>, int>> Q;
        auto pos = gyul[i];
        Q.push({ pos, 0 });
        visited[pos.first][pos.second] = 1;
        while (!Q.empty()) {
            auto cur = Q.front().first;
            int dist = Q.front().second;
            Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                else if (virus[nx][ny] == 1) {
                    flag = true;
                    ans[pos.first][pos.second] = dist + 1;
                }
                else if (board[nx][ny] != 0 && visited[nx][ny] == 0) {
                    Q.push({ {nx, ny}, dist + 1 });
                    visited[nx][ny] = 1;
                }

                if (flag) {
                    break;
                }
            }
            if (flag)
                break;
            ans[pos.first][pos.second] = -2;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}