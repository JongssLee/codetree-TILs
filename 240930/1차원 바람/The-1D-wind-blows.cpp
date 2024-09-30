#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int n, m, q;
int board[1000][1000] = { 0, };
int temp[1000][1000] = { 0, };


int res = 0;
int dx[3] = { 1,1,1 };
int dy[3] = {-1, 0, 1};
int dp[3000][3000];
int main() {
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	while (q--) {
		int x;
		char y;
		bool z;
		cin >> x >> y;
		if (y == 'L')
			z = true;
		else
			z = false;
		int check[1000] = { 0, };
		stack <pair<int, bool>> S;
		S.push({ x,z });
		while (!S.empty()) {
			auto cur = S.top();
			S.pop();
			check[cur.first] = 1;
			//바람 분다
			for (int i = 1; i <= m; i++) {
				if (cur.second) {
					//왼쪽에서 바람 -> 오른쪽으로 한칸씩
					if (i == m) {
						temp[cur.first][1] = board[cur.first][i];
					}
					else
						temp[cur.first][i + 1] = board[cur.first][i];
				}
				else {
					//오른쪽 바람 -> 왼쪽으로 한칸씩
					if (i == 1) {
						temp[cur.first][m] = board[cur.first][i];
					}
					else
						temp[cur.first][i - 1] = board[cur.first][i];
				}
			}
			//보드에 temp 적용
			for (int i = 1; i <= m; i++) {
				board[cur.first][i] = temp[cur.first][i];
			}

			//위아래 기준 겹치는게 있는지
			//위 먼저
			if (cur.first > 1) {
				if (check[cur.first - 1] == 0) {
					for (int i = 1; i <= m; i++) {
						if (board[cur.first - 1][i] == board[cur.first][i]) {
							S.push({ cur.first - 1, 1 - cur.second });
							break;
						}
					}
				}
			}

			//아래
			if (cur.first < n) {
				if (check[cur.first + 1] == 0) {
					for (int i = 1; i <= m; i++) {
						if (board[cur.first + 1][i] == board[cur.first][i]) {
							S.push({ cur.first + 1, 1 - cur.second });
						}
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << board[i][j] << ' ';

		}
		cout << '\n';
	}
	
}