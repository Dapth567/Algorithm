#include <bits/stdc++.h>

using namespace std ;
const int inf = 1e8 + 7 ;
int main() {
    int n , k ; cin >> n >> k ;
    int dp[k][n+1] = {0};
    dp[0][1] = 1 ;
    dp[1][1] = 1 ;
    for (size_t i = 2; i <= n; i++)
    {
        for (size_t j = 0; j < k; j++)
        {
            if (j == 0){
                dp[j][i] += dp[j][i-1] % inf ;
                dp[j][i] += dp[k][i-1] % inf ;
            } else if(j == k){
                dp[0][i] += dp[j][i-1] % inf ;
            } else {
                dp[j][i] += dp[j-1][i-1] % inf ;
            }
            dp[1][i] += dp[j][i-1] % inf;
        }
    }
    int ans = 0 ;
    
    for (size_t i = 0; i < k; i++)
    {
        ans += dp[i][n] % inf ;
    }
    cout << ans ;

}