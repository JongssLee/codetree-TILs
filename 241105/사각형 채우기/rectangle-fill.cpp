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
    dp[1] = 1;
    dp[2] = 2;
    
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] % 10007 + dp[i - 2]% 10007;
        dp[i] %= 10007;
    }
    
    cout << dp[n];
    return 0;
}