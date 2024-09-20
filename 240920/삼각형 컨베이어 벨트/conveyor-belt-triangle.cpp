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
	t = t % (n * 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			
		}
	}
	

	while (t--) {
		//0행은 열+1
		//1행은 열-1
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 2 && j == n - 1) {
					temp[0][0] = board[i][j];
				}
				else if (j == n - 1) {
					temp[i + 1][0] = board[i][j];
				}
				else {
					temp[i][j + 1] = board[i][j];
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = temp[i][j];
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';

		}
		cout << '\n';
	}

	
}