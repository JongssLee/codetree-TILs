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
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	//행 비교
	for (int i = 1; i <= n; i++) {
		int before = -1;
		bool same = false;
		int temp = 1;
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == before) {
				temp++;
				
			}
			else {
				before = board[i][j];
				temp = 1;
			}
			if (temp == m) {
				res++;
				break;
			}
		}
	}
	for (int j = 1; j <= n; j++) {
		int before = -1;
		bool same = false;
		int temp = 1;
		for (int i = 1; i <= n; i++) {
			if (board[i][j] == before) {
				temp++;

			}
			else {
				before = board[i][j];
				temp = 1;
			}
			if (temp == m) {
				res++;
				break;
			}
		}
	}
	cout << res;

}