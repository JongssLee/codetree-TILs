#include <iostream>
#include <stack>
#include <utility>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int board[109][109] = { 0, };
int n, k;
int r, c;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    cin >> r >> c;
    int temp_max = board[r][c];
    while (k--) {
        int temp = -1;
        int visit[109][109] = { 0, };
        queue<pair<int, int>>Q;
        Q.push({ r,c });
        visit[r][c] = 1;
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
                if (visit[nx][ny] == 0 && board[nx][ny] < temp_max) {
                    visit[nx][ny] = 1;
                    Q.push({ nx, ny });
                    if (temp < board[nx][ny]) {
                        temp = board[nx][ny];
                    }
                }
            }
        }

        if (temp == -1) {
            cout << r << ' ' << c;
            return 0;
        }

        bool check = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (visit[i][j] == 1 && board[i][j] == temp && check == false) {
                    check = true;
                    r = i;
                    c = j;
                    temp_max = temp;
                }
            }
        }
    }
    cout << r << ' ' << c;
}