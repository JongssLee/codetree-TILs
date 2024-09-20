#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int n, t;
int board[1000][1000] = { 0, };
int temp[1000][1000] = { 0, };
stack < pair<pair<int, int>, int>> S;
int res = 0;
int dx[3] = { 1,1,1 };
int dy[3] = {-1, 0, 1};
int dp[3000][3000];
int main() {
	cin >> n>>t;
	t = t % (n * 2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			temp[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		board[1][i] = temp[1][n - 1 - i];
	}

	while (t--) {
		//0행은 열+1
		//1행은 열-1
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				temp[1][i] = board[0][i];
			}
			else {
				temp[0][i + 1] = board[0][i];
			}
		}
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				temp[0][0] = board[1][0];
			}
			else
				temp[1][i-1] = board[1][i];
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = temp[i][j];
			}
		}


	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 1) {
				cout << board[i][n - 1 - j] << ' ';
			}
			else
				cout << board[i][j] << ' ';
		}
		cout << '\n';
	}

	
}