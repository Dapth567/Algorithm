#include <bits/stdc++.h>
//first solver
using namespace std ;
const int inf = 1e9 ;
int dx[4] = {0,0,1,-1} , dy[4] = {1,-1,0,0} ;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r , c ; cin >> r >> c ;
    vector<vector<char>> map(r,vector<char>(c,'0')) ;
    vector<vector<bool>> visit(r,vector<bool>(c,false)) ;
    queue<tuple<int,int,int>> order ;
    pair<int,int> W = {0,0};
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            cin >> map[i][j] ;
            if (map[i][j] == 'S'){
                order.push({0,i,j}) ;
            }
            if (map[i][j] == 'W'){
                W = {i,j};
            }                       
        }
    }
    int ans ;
    bool found = false ;
    while (!found)
    {
        if (order.empty()){
            break;
        }
        auto [t,x,y] = order.front();
        order.pop() ;
        if (visit[x][y]){
            continue;
        } else {
            visit[x][y] = true ;
        }
        
        if (map[x][y] == '.' || map[x][y] == 'S' || map[x][y] == 'W'){
            for (size_t i = 0; i < 4; i++)
            {
                int sx = x + dx[i] , sy = y + dy[i] ;
                if (sx >= 0 && sy >= 0 && sx <= r-1 && sy <= c-1 && visit[sx][sy] == false){
                    
                    order.push({t+1,sx,sy});
                }
            }
        } else if(map[x][y] == 'B') {
            if (visit[W.first][W.second] == false ){
                order.push({t+1,W.first,W.second});
            }
            for (size_t i = 0; i < 4; i++)
            {
                int sx = x + dx[i] , sy = y + dy[i] ;
                if (sx >= 0 && sy >= 0 && sx <= r-1 && sy <= c-1 && visit[sx][sy] == false){
                    order.push({t+1,sx,sy});
                }
            }
        } else if(map[x][y] == 'T') {
            found = true ;
            ans = t ;
            break ;
        }

    }
    if (found){
        cout << ans ;
    } else {
        cout << -1 ;
    }
    
}