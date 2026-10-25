#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n,k,siz,index,backtrack;
    cin >> n >> k ;
    vector<int> piece(k) , dp(n,0) ;

    for (size_t i = 0; i < k; i++)
    {
        cin >> siz ;
        piece[i] = siz ;
    }

    dp[0] = 0 ;
    for (size_t i = 1; i < n+1; i++)
    {
        for (size_t j = 0; j < k; j++)
        {
            index = i-1 ;
            backtrack = i - piece[j];
            if (backtrack == 0){
                dp[index] += 1  ; 
            } else if (backtrack > 0){
                dp[index] += (dp[index-piece[j]]) ;
            }
        }
    }

  cout << dp[n-1] ;

    
    
    
}