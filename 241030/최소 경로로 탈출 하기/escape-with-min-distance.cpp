#include <iostream>
#include <stack>
#include <utility>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int board[109][109] = { 0, };
int visited[109][109] = { 0, };
int n, m, k;
int r, c;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<pair<int, int>, int>> Q;
    Q.push({ {0,0}, 0 });
    visited[0][0] = 1;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first.first + dx[dir];
            int ny = cur.first.second + dy[dir];
            int dist = cur.second;

            if (nx == n - 1 && ny == m - 1) {
                cout << dist + 1;
                return 0;
            }

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == 1 && visited[nx][ny] == 0) {
                Q.push({ {nx, ny}, dist + 1 });
                visited[nx][ny] = 1;
            }
        }
    }
    cout << -1;
    return 0;
}