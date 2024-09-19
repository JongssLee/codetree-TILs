#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int n, m;
int board[1000][1000] = { 0, };
stack < pair<pair<int, int>, int>> S;
int res = 0;
int dx[3] = { 1,1,1 };
int dy[3] = {-1, 0, 1};
int dp[3000][3000];
int main() {
	cin >> n>>m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	//r 자 모형
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			int minVal = 2000;
			int cnt = 0;
			for (int x = i; x <= i + 1; x++) {
				for (int y = j; y <= j + 1; y++) {
					cnt += board[x][y];
					minVal = min(minVal, board[x][y]);
				}
			}
			cnt -= minVal;
			res = max(res, cnt);
		}
	}
	// 1*3모형
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - 2; j++) {
			int cnt = 0;
			for (int y = j; y <= j + 2; y++) {
				cnt += board[i][y];
			}
			res = max(res, cnt);
		}
	}
	//3*1
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n - 2; i++) {
			int cnt = 0;
			for (int x = i; x <= i + 2; x++) {
				cnt += board[x][j];
			}
			res = max(res, cnt);
		}
	}
	cout << res;

}