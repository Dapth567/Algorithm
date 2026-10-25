#include <bits/stdc++.h>
using namespace std ;
int r , c , dx[4] = {-1,0,0,1} ,dy[4] = {0,-1,1,0};
bool inbound(int row , int col){
    return (row >= 0 && col >= 0 && row <= r -1 && col <= c - 1) ;
}
int main(){
     cin >> r >> c ;
    vector<int> row(c,0);
    vector<vector<int>> grid(r,row);
    set<tuple<int,int,int>> order ; // time and grid
    for (size_t i = 0; i < r; i++){
        for (size_t j = 0; j < c; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 1){
                order.insert({1,i,j});
            }
        }
    }
    bool found = false ;
    while (!order.empty()){
        auto [time,x,y] = *(order.begin());
        for (size_t i = 0; i < 4; i++) {
            int shiftx  = x+dx[i] , shifty = y+dy[i] ;
            if (inbound(shiftx,shifty)) {
                if (grid[shiftx][shifty] == 0){
                    grid[shiftx][shifty] = 1 ;
                    order.insert({time+1,shiftx,shifty});
                } else if (grid[shiftx][shifty] == 2 ){
                    cout << time + 1 ;
                    found = true ;
                    break;
                }
            }
        }
        if (found) {
            break;
        }
        order.erase(order.begin());
    }
}