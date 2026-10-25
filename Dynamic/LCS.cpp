#include <bits/stdc++.h>

using namespace std ;

int main(){
    string s1,s2 ;
    cin >> s1 >> s2 ;
    int m = s1.size() , n = s2.size() ;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0)) ;
    for (size_t i = 1; i <= m; i++) {
        for (size_t j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1 ;
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
            }
        }
    }
    cout << dp[m][n] ;
}