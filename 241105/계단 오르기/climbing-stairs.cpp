#include <iostream>
#include <stack>
#include <utility>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int dp[1001] = { 0, };
int vs[3000009] = { 0, };
int main() {
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    int n;
    cin >> n;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    cout << dp[n];
    return 0;
}