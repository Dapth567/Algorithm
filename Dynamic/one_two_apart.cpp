#include <bits/stdc++.h>

using namespace std ;
const int mod = 1e9 + 7 ;
int main(){
    int n ; cin >> n ;
    if (n == 1){
        cout << 3 ;
    } else if(n == 2) {
        cout << 7 ;
    } else {
        int dp[n+1][5] = {0} ; 
        dp[2][0] = 1 ; dp[2][1] = 2 ; dp[2][2] = 1 ; dp[2][3] = 2  ; dp[2][4] = 1 ;
        for (size_t i = 3; i <= n; i++) {
            dp[i][0] += dp[i-1][0] % mod ;
            dp[i][0] += dp[i-1][2] % mod ;
            dp[i][0] += dp[i-1][4] % mod ;
            dp[i][1] += dp[i-1][1] % mod ;
            dp[i][1] += dp[i-1][0] % mod ;
            dp[i][1] += dp[i-1][2] % mod ;
            dp[i][2] += dp[i-1][1] % mod ;
            dp[i][3] += dp[i-1][0] % mod ;
            dp[i][3] += dp[i-1][3] % mod ;
            dp[i][3] += dp[i-1][4] % mod ;
            dp[i][4] += dp[i-1][3] % mod ;
        }
        cout << (dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4])%mod ;
    }
}