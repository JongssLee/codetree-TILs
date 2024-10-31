#include <iostream>
#include <stack>
#include <utility>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int board[109][109] = { 0, };

int n, k, wall_cnt=0;
int r, c;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> wall;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                wall.push_back({ i, j });
                wall_cnt++;
            }
        }
    }
    int startX, startY, goalX, goalY;
    cin >> startX >> startY >> goalX >> goalY;
    startX--;
    startY--;
    goalX--;
    goalY--;
    if (startX == goalX && startY == goalY) {
        cout << 0;
        return 0;
    }
    vector<int>comb;
    for (int i = 0; i < k; i++) {
        comb.push_back(0);
    }
    for (int i = 0; i < wall_cnt-k; i++) {
        comb.push_back(1);
    }
    int ans = 100009;
    do {
        int temp_board[109][109];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp_board[i][j] = board[i][j];
            }
        }
        for (int i = 0; i < comb.size(); i++) {
            if (comb[i] == 0) {
                temp_board[wall[i].first][wall[i].second] = 0;
            }
        }
        int visited[109][109] = { 0, };
        queue<pair<pair<int, int>, int>> Q;
        Q.push({ {startX, startY}, 0 });
        visited[startX][startY] = 1;
        bool flag = false;
        while (!Q.empty()) {
            auto cur = Q.front().first;
            int dist = Q.front().second;

            Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = dx[dir] + cur.first;
                int ny = dy[dir] + cur.second;

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                else if (nx == goalX && ny == goalY) {
                    flag = true;
                    ans = min(ans, dist + 1);
                }
                else if (temp_board[nx][ny] == 0 && visited[nx][ny] == 0) {
                    Q.push({ {nx, ny}, dist + 1 });
                    visited[nx][ny] = 1;
                }

                if (flag)
                    break;
            }
            if (flag)
                break;
        }
    } while (next_permutation(comb.begin(), comb.end()));
    if (ans == 100009)
        ans = -1;
    cout << ans;
    return 0;
}