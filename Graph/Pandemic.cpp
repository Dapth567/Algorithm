// #include <bits/stdc++.h>

// using namespace std ; 

// bool inbound(pair<int,int> direction, vector<vector<int>>& map){
//     int rx = direction.first, cx = direction.second ;
//     return (rx >= 0 && rx <= map.size()-1 && cx >= 0 && cx <= map[0].size()-1);
// }

// void spread(vector<vector<bool>>& visit, vector<vector<int>>& map, priority_queue<pair<int,pair<int,int>>>& high){
//     while (!high.empty())
//     {
//         int pow = high.top().first ;
//         if (pow == -1){
//             high.pop();
//         } else {
//             if (inbound(high.top().second,map)){
//                 int rx = (high.top().second).first , cx = (high.top().second).second ;
//                 if (map[rx][cx] != 2){
//                     if (!visit[rx][cx]){
//                         visit[rx][cx] = true ;
//                         pair<int,int> down = {rx+1,cx} , up = {rx-1,cx} , left = {rx,cx-1} , right = {rx,cx+1};
//                         high.push({pow-1,up}); high.push({pow-1,down}); high.push({pow-1,left}); high.push({pow-1,right});
//                     } else {
//                         high.pop();
//                     }
//                 } else {
//                     high.pop();
//                 }
//             } else {
//                 high.pop();
//             }
//         }    
//     }
    
// }

// int main() {
//     std::ios_base::sync_with_stdio(false); std::cin.tie(0);
//     int r ,c ,day ;
//     cin >> r >> c >> day ;
//     vector<int> row(c,0) ;
//     vector<vector<int>> map(r,row);
//     vector<bool> row_vis(c,false);
//     vector<vector<bool>> visit(r,row_vis);
//     priority_queue<pair<int,pair<int,int>>> high ;
//     for (size_t i = 0; i < r; i++)
//     {
//         for (size_t j = 0; j < c; j++)
//         {
//             cin >> map[i][j] ;
//             if (map[i][j] == 1){
//                 high.push({day,{i,j}});
//             }
//         }
//     }
//     spread(visit,map,high);
//     int count = 0 ;
//     for (auto v : visit)
//     {
//         for (auto num : v)
//         {
//             if (num){
//                 count +=1 ;
//             }
//         }
//     }
//     cout << count ;
// }



#include <bits/stdc++.h>

using namespace std ;
int dx[4] = {0,0,-1,1} , dy[4] = {-1,1,0,0} ;
int main(){
    int count = 0 ;
    int r , c , sp ; cin >> r >> c >> sp ;
    vector<int> row(c,0);
    vector<vector<int>> grid(r,row) ;
    set<tuple<int,int,int>> order ;
    for (size_t i = 0; i < r; i++){
        for (size_t j = 0; j < c; j++){
            cin >> grid[i][j] ;
            if (grid[i][j] == 1){
                order.insert({0,i,j});
                count++;
            }
        }
    }
    while (!order.empty())
    {
        auto [s,rx,cx] = *(order.begin());
        if (s < sp){
            for (size_t i = 0; i < 4; i++)
            {
                int x = rx + dx[i] , y = cx + dy[i] ;
                if (x >= 0 && y >= 0 && x <= r-1 && y <= c-1 && grid[x][y] == 0){
                    grid[x][y] = 1 ;
                    // cout << "send " << s-1 << " to " << x << " "<< y << "\n";
                    order.insert({s+1,x,y});
                    count++;
                }
            }
        }
        order.erase(order.begin());
    }
    // for (auto f : grid)
    // {
    //     for (auto num : f)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << "\n";
    // }
    
    cout << count ;
}