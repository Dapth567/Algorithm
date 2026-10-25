#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n ,value,ans = INT_MIN;
    cin >> n ;
    vector<int> dp(n) ;
    for (size_t i = 0; i < n; i++)
    {
        cin >> value;
        if (i == 0){
            dp[0] = value ;
        } else if (i == 1){
            dp[1] = value ;
        } else if (i == 2){
            dp[2] = dp[0] + value ;
        } else {
            dp[i] = max(value + dp[i-2],value + dp[i-3]) ;
        }
    }

    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << "this is dp at i " << dp[i] << endl;
    // }
    

    for (size_t i = 0; i < 3; i++)
    {
        if (n-1-i <= 0){

        } else {
            ans = max(ans,dp[n-i-1]);
        }
    }
    cout << ans ;
    
    
}