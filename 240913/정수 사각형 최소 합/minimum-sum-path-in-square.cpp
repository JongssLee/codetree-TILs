#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int n, m;
int board[3000][3000] = { 0, };
stack < pair<pair<int, int>, int>> S;
int res = 0;
int dx[3] = { 1,1,1 };
int dy[3] = {-1, 0, 1};
int dp[3000][3000];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	dp[1][1] = board[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) {
			if (j == n) {
				dp[i][j] = dp[i - 1][j] + board[i][j];
			}
			else if (i == 1) {
				dp[i][j] = dp[i][j + 1] + board[i][j];
			}
			else {
				dp[i][j] = min(dp[i - 1][j], dp[i][j + 1]) + board[i][j];
			}
		}
	}
	cout << dp[n][1];
}