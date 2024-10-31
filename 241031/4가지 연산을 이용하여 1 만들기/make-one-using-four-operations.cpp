#include <iostream>
#include <stack>
#include <utility>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int dp[3000009] = { 0, };
int vs[3000009] = { 0, };
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    queue<pair<int, int>> Q;
    Q.push({ n,0 });
    vs[n] = 1;
    while (!Q.empty()) {
        int cur = Q.front().first;
        int dist = Q.front().second;
        Q.pop();
        if (cur == 2 || cur == 3) {
            cout << dist + 1;
            return 0;
        }
        //+1
        if (cur + 1 < 3000009) {
            if (vs[cur + 1] == 0) {
                Q.push({ cur + 1, dist + 1 });
                vs[cur + 1] = 1;
            }
        }
        if (cur - 1 > 0) {
            if (vs[cur - 1] == 0) {
                Q.push({ cur - 1, dist + 1 });
                vs[cur - 1] = 1;
            }
        }
        if (cur % 2 == 0) {
            if (vs[cur / 2] == 0) {
                Q.push({ cur / 2, dist + 1 });
                vs[cur / 2] = 1;
            }
        }
        if (cur % 3 == 0) {
            if (vs[cur / 3] == 0) {
                Q.push({ cur / 3, dist + 1 });
                vs[cur / 3] = 1;
            }
        }
    }
    return 0;
}