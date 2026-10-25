#include <bits/stdc++.h>

using namespace std ;

int main(){
    int n , m ; cin >> n >> m ;
    string s1 , s2 ;
    cin >> s1 >> s2 ;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;
    vector<char> ans ;
    for (size_t i = 0; i <= n; i++)
    {
        for (size_t j = 0; j <= m; j++)
        {
            cin >> dp[i][j];
        }
    }
    int x = n ,y = m ;
    while (x != 0 && y != 0)
    {
        if (dp[x][y]  == dp[x-1][y-1] + 1 && dp[x][y] == dp[x][y-1] + 1 && dp[x][y] == dp[x-1][y] + 1) {
            ans.push_back(s2[y-1]);
            x--; y-- ;
            // cout << "here" ;
        } else {
            if (dp[x][y] == dp[x][y-1]) {
                y--;
            } else if (dp[x][y] == dp[x-1][y]){
                x--;
            }
            
        }
    }
    reverse(ans.begin(),ans.end());
    for (auto c : ans )
    {
        cout << c ;
    }
    
    
}