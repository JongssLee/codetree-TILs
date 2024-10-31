#include <iostream>
#include <stack>
#include <utility>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int board[109][109] = { 0, };

int n, h, m;
int r, c;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> human;
int ans[109][109] = { 0, };
int safe[109][109] = { 0, };
int main() {
    cin >> n >> h>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 3) {
                safe[i][j] = 1;
            }
            else if (board[i][j] == 2) {
                human.push_back({ i,j });
            }
        }
    }
    for (int i = 0; i < human.size(); i++) {
        int visited[109][109] = { 0, };
        queue<pair<pair<int, int>, int>> Q;
        auto start = human[i];
        Q.push({ start, 0 });
        visited[start.first][start.second] = 1;
        bool flag = false;
        while (!Q.empty()) {
            auto cur = Q.front().first;
            int dist = Q.front().second;
            Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                else if (safe[nx][ny] == 1 && visited[nx][ny]  ==0) {
                    ans[human[i].first][human[i].second] = dist + 1;
                    flag = true;
                    visited[nx][ny] = 1;
                }
                else if (board[nx][ny] != 1 && visited[nx][ny] == 0) {
                    Q.push({ {nx, ny}, dist + 1 });
                    visited[nx][ny] = 1;
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        if (ans[human[i].first][human[i].second] == 0)
            ans[human[i].first][human[i].second] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}