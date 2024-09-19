#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int n, m;
int board[100][100] = { 0, };
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
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= n-2; j++) {
			int temp=0;
			for (int x = i; x <= i + 2; x++) {
				for (int y = j; y <= j + 2; y++) {
					if (board[x][y] == 1) {
						temp++;
					}
				}
			}
			res = max(res, temp);
		}
	}
	cout << res;
}