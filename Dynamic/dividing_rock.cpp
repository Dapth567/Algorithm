#include <bits/stdc++.h>

using namespace std ;

int dp[1001][1001] = {0};

int cal(int n,int k){
    if(dp[n][k] == 0){
        if (n == k || k == 1 ){
            dp[n][k] = 1 ;
            return 1 ;
        } else {
            dp[n][k] = ((cal(n-1,k-1)%1997) + (k%1997 * cal(n-1,k)%1997)%1997)%1997;
            return dp[n][k] ;
        } 
    } else {
        return dp[n][k];
    }
}

int main() {
    int n,k,ans ;
    cin >> n >> k ;
    if (n >= k){
        ans = cal(n,k);
    } else {
        ans = 0 ;
    }
    cout << ans ;
}