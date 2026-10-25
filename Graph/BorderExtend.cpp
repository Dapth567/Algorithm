#include <bits/stdc++.h>

using namespace std ;

int r , c , e ;
int dx[4] = {0,1,-1,0},dy[4] = {1,0,0,-1} ;

bool inbound(int co ,int ro){
    return (co >= 0 && co <= c-1 && ro >= 0 && ro <= r -1);
}

int main() {
    cin >> r >> c >> e ;
    vector<int> row(c,0) ;
    vector<vector<int>> grid(r,row) ;
    vector<bool> vis_row(c,false) ;
    vector<vector<bool>> visit(r,vis_row) ;
    queue<pair<int,pair<int,int>>> spand ;
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            cin >> grid[i][j] ;
            if(grid[i][j]){
                spand.push({e,{i,j}});
                // cout << "1try push" << e << " and" << i << " " << j << "\n";
            }
        }
    }
    while (!spand.empty())
    {
        int co , ro , ex_pow ;
        co = ((spand.front()).second).second ;
        ro = ((spand.front()).second).first ;
        ex_pow = (spand.front()).first ;
        if (inbound(co,ro)){
            if (!visit[ro][co] && ex_pow >= 0) {
                visit[ro][co] = true ;
                if (grid[ro][co] != 1){
                    grid[ro][co] = 2 ;
                }
                for (size_t i = 0; i < 4; i++)
                {
                    // cout << "2try push" << ex_pow-1 << " and" << ro+dx[i] << " " << co+dy[i] << "\n";
                    spand.push({ex_pow-1,{ro+dx[i],co+dy[i]}}) ;
                }
            } 
        }
        spand.pop();
    }
    
    for (auto k : grid)
    {
        for (auto num : k)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
    
}