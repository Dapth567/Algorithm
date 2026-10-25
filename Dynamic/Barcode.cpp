#include <bits/stdc++.h>

using namespace std ;


int main() {
    int n ,m , k ;
    cin >> n >> m >> k ;
    int dp[n][m][k] = {0};
    dp[0][0][0] = 2 ;
}





















// void gen_barcode(int n ,int& m ,int streak_count,int k ,int& ans ,bool lastfill0){

//     if (k < 0 || streak_count > m){
//         return ;
//     }

//     if(n == 0 && k == 0){
//         ans++;
//         return ;
//     }

//     if(lastfill0){
//         gen_barcode(n-1,m,streak_count+1,k,ans,true);
//         gen_barcode(n-1,m,1,k-1,ans,false);
//     } else {
//         gen_barcode(n-1,m,1,k-1,ans,true);
//         gen_barcode(n-1,m,streak_count+1,k,ans,false);
//     }


// }

// int main() {
//     int n , m , k ,ans = 0;
//     cin >> n >> m >> k ;
//     gen_barcode(n-1,m,1,k,ans,true);
//     cout << ans ;
// }