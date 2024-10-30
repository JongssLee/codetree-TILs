#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    return 0;
}#include <iostream>
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
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int main() {
    cin >> n ;
    int startX, startY, goalX, goalY;
    cin >> startX >> startY >> goalX >> goalY;
    startX--;
    startY--;
    goalX--;
    goalY--;

    queue<pair<pair<int, int>, int>> Q;
    Q.push({ {startX,startY}, 0 });
    visited[startX][startY] = 1;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.first.first + dx[dir];
            int ny = cur.first.second + dy[dir];
            int dist = cur.second;

            if (nx == goalX && ny == goalY) {
                cout << dist + 1;
                return 0;
            }

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny] == 0) {
                Q.push({ {nx, ny}, dist + 1 });
                visited[nx][ny] = 1;
            }
        }
    }
    cout << -1;
    return 0;
}