#include <bits/stdc++.h>

using namespace std ;
const int dx[4] = {-1,1,0,0} , dy[4] = {0,0,1,-1} ;
int main(){
std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);

    int r , c ; cin >> r >> c ;
    pair<int,int> start,end ;
    vector<char> row(c,'0');
    vector<vector<char>> grid(r,row) ;
    // set<tuple<int,int,int>> order ;
    queue<tuple<int,int,int>> order ;
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            char ch ; cin >> grid[i][j] ;

            if (grid[i][j] == 'S'){
                start = {i,j};
                order.push({0,i,j}) ;
            }
        }
    }
    // for (auto ee : grid)
    // {
    //     for (auto jjj : ee)
    //     {
    //         cout << jjj << " ";
    //     }
    //     cout << "\n";
    // }
    bool found  = false;
    while (!order.empty())
    {
        auto [step,x,y] = (order.front());
        // cout << "current order = " << step << " " << x << " " << y << "\n" ;
        order.pop();
        // if (grid[x][y] = 'v'){
        //     order.pop();
        //     continue;
        // }
        if (grid[x][y] == 'v'){
            continue;
        }

        if (grid[x][y] == '.' || grid[x][y] == 'S'){
            grid[x][y] = 'v' ;
            for (size_t i = 0; i < 4; i++)
            {
                int sx = x + dx[i] , sy = y + dy[i] ;
                if (sx >= 0 && sy >= 0 && sx <= r-1 && sy <= c-1){
                    if (grid[sx][sy] != 'v'){
                        order.push({step+1,sx,sy}) ;
                    }
                    if (grid[sx][sy] == 'T') {
                        cout << step +1 ;
                        found = true ;
                    }
                }
            }
            
        } else if (grid[x][y] == '#'){
            grid[x][y] = 'v' ;
            for (size_t i = 0; i < 4; i++)
            {
                int sx = x + dx[i] , sy = y + dy[i] ;
                while (sx >= 0 && sy >= 0 && sx <= r-1 && sy <= c-1)
                {
                    if (grid[sx][sy] != 'v'){
                        order.push({step+1,sx,sy}) ;
                        sx += dx[i];
                        sy += dy[i];
                    }
                    if (grid[sx][sy] == 'T') {
                        cout << step +1 ;
                        found = true ;
                    }
                    // order.push({step+1,sx,sy});

                }
            }
        }
        if(found){
            break;
        }
        
    }
    // for (auto ee : grid)
    // {
    //     for (auto jjj : ee)
    //     {
    //         cout << jjj << " ";
    //     }
    //     cout << "\n";
    // }
    
    
}