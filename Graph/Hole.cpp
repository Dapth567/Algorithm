#include <bits/stdc++.h>

using namespace std ;

int dx[4] = {0,1,-1,0} , dy[4] = {1,0,0,-1} ;
int n ;

bool inbound(int x ,int y){
    return (x >= 0 && y >= 0 && x <= n-1 && y <= n-1);
}https://github.com/Tanakit-Kit/HW-SynLab2025.git
void dfs(vector<vector<int>>& grid,int x ,int y,set<tuple<int,int,int>>& order){
    for (size_t i = 0; i < 4; i++)
    {
        int sx = x+dx[i] , sy = y+dy[i] ;
        if (inbound(sx,sy)){
            if (grid[sx][sy] == 0){
                grid[sx][sy] = 2 ;
                order.insert({0,sx,sy});
                dfs(grid,sx,sy,order);
            }
        }
    }   
}
int main() {
    int x , y,xh,yh;
    cin >> n ;
    vector<int> row(n,0);
    vector<vector<int>> grid(n,row) ;
    cin >> x >> y ;
    
    grid[x-1][y-1] = 2 ;
    for (size_t i = 0; i < n; i++)
    {
        cin >> xh >> yh ;
        grid[xh-1][yh-1] = 1 ;
    }

    set<tuple<int,int,int>> order ;
    order.insert({0,x-1,y-1});
    dfs(grid,x-1,y-1,order);
    for (auto v :grid)
    {
        for (auto num : v)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    bool found = false ;
    int ans = 0 ;
    while (!found)
    {
        auto [dist,x,y] = *(order.begin());
        for (size_t i = 0; i < 4; i++)
        {
            int sx = x+dx[i] , sy = y+dy[i] ;
            if (inbound(sx,sy)){
                if (grid[sx][sy] == 1){
                    grid[sx][sy] = 2 ;
                    order.insert({dist+1,sx,sy});
                } else if (grid[sx][sy] == 0){
                    ans = dist ;
                    found = true ;
                    break;
                }
            } else {
                order.erase(order.begin());
                break;
            }
        }
        if (found){
            break;
        }
        order.erase(order.begin());
    }
    cout << ans ;
}