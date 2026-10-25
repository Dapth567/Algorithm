#include <bits/stdc++.h>

using namespace std ;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n , mw ; cin >> n >> mw;
    int w[n+1] = {0} , p[n+1] = {0};
    for (size_t i = 1; i <= n; i++) {
        cin >> p[i] ;
    }
    for (size_t i = 1; i <= n; i++) {
        cin >> w[i] ;
    }    
    int dp[n+1][mw+1];
    for (size_t i = 0; i <= n; i++)
    {
        for (size_t j = 0; j <= mw; j++)
        {
            cin >> dp[i][j] ;
        }
    }
    int x = n , y = mw ;
    set<int> choose ;
    while (x != 0 && y != 0)
    {
        if (dp[x][y] == dp[x-1][y]){
            x -= 1 ;
        } else {
            for (size_t i = 1; i <= n; i++)
            {
                if (choose.find(i) == choose.end() && y - w[i] >= 0 && dp[x-1][y-w[i]] == dp[x][y] - p[i]){
                    x -= 1 ;
                    y -= w[i] ;
                    choose.insert(i);
                }
            }
        }
    }
    cout << choose.size() << "\n" ;
    for (auto k : choose)
    {
        cout << k << " ";
    }
    
    
}