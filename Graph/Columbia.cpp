#include <bits/stdc++.h>

using namespace std ;
const int inf = 1e9 ;
int dx[4] = {0,0,-1,1} , dy[4] = {-1,1,0,0} ;
int main() {
    int r , c ; cin >> r >>c ;
    int map[r][c] , dist[r][c]  ;
    for (size_t i = 0; i < r; i++) {
        for (size_t j = 0; j < c; j++) {
            cin >> map[i][j] ;
            dist[i][j] = inf ;
        }
    }
    set<tuple<int,int,int>> order ;
    order.insert({0,0,0});
    while (!order.empty())
    {
        auto [w,u,v] = *(order.begin());
        order.erase(order.begin()) ;
        if (dist[u][v] > w){
            dist[u][v] = w ;
            for (size_t i = 0; i < 4; i++)
            {
                int sx = u + dx[i] , sy = v + dy[i] ;
                if (sx >= 0 && sy >= 0 && sx <= r-1 && sy <= c -1){
                    order.insert({w+map[sx][sy],sx,sy}) ;
                }
            }
        }
        
    }
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            cout << dist[i][j] << " " ; 
        }
        cout << "\n";
    }
    
}