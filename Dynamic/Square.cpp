#include <bits/stdc++.h>

using namespace std ;

int main() {
    int r , c , ans = INT_MIN ;
    cin >> r >> c ;
    int dp[r][c] = {0} ;
    string word ;
    for (size_t i = 0; i < r; i++){
        cin >> word ;
        for (size_t j = 0; j < c; j++){
            dp[i][j] =  word[j] - 48 ;
            if(dp[i][j] && i && j){
                dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]}) + 1;
            }
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans ;
}