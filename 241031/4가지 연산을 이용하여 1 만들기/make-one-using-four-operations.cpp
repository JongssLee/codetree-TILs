#include <iostream>
#include <stack>
#include <utility>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int dp[1000009] = { 0, };
int main() {
    int n;
    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }
    for (int i = n; i >= 3; i--) {
        dp[i - 1] = min(dp[i] + 1, dp[i - 1]);
    }
    cout << dp[n];
    return 0;
}