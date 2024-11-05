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
    dp[1] = 2;
    dp[2] = 7;
    
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1]*2) % 1000000007 + (dp[i - 2]*4)% 1000000007;
        dp[i] %= 1000000007;
    }
    
    cout << dp[n];
    return 0;
}