#include <bits/stdc++.h>

using namespace std ;
int n ;

int main() {

    int value ;
    cin >> n ;
    vector<int> arr(n) , dp(n);

    for (size_t i = 0; i < n; i++) {
        cin >> value ;
        if (i == 0){
            dp[0] = value ;
        } else if (i == 1){
            dp[1] = dp[0] + value ;
        }else if (i == 2){
            dp[2] = max(dp[0],dp[1]) + value ;
        } else if (i > 2) {
            dp[i] = max(max(dp[i-1],dp[i-2]),dp[i-3]) + value ;
        }

        if (i == arr.size()-1){
            cout << dp[i] ;
        }
    }

}