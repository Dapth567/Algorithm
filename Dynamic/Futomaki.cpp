// #include <bits/stdc++.h>

// using namespace std ;
// int a[5005] , dp[5005][5005] ;

// int main() {
//     int n ; cin >> n ;
//     for (size_t i = 1; i <= n; i++)
//     {
//         cin >> a[i] ;
//     }
//     for (size_t len = 2; len <= n; len+=2)
//     {
//         for (size_t i = 1; i <= n - len + 1; i++)
//         {
//             int j = i + len - 1 ;
//             if (len == 2){
//                 dp[i][j] = max(a[i],a[j]);
//             } else {
//                 int option1 = max(a[i],a[i+1]) + dp[i+2][j] ;
//                 int option2 = max(a[j],a[j-1]) + dp[i][j-2] ;
//                 int option3 = max(a[i],a[j]) + dp[i+1][j-1] ;
//                 dp[i][j] = max({option1,option3,option2}) ;
//             }
            
//         }
        
//     }
//     cout << dp[1][n];
// }


#include <bits/stdc++.h>

using namespace std ; 

int main() {
    int n ; cin >> n ;
    int a[n+1] = {0} , dp[n+1][n+1] = {0} ;
    for (size_t i = 1; i <= n; i++) { cin >> a[i] ; }
    for (size_t len = 2; len <= n; len+=2) {
        for (size_t i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1 ;
            if (len == 2){
                dp[i][j] = max(a[i],a[j]);
            } else {
                int option1 = max(a[i],a[i+1]) + dp[i+2][j] ;
                int option2 = max(a[i],a[j]) + dp[i+1][j-1];
                int option3 = max(a[j],a[j-1]) + dp[i][j-2];
                dp[i][j] = max({option1,option2,option3}) ;
            }
        }
    }
    cout << dp[1][n];
}