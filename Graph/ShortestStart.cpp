#include <bits/stdc++.h>

using namespace std ;

const int inf = 1e9 ;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v , e , s ; cin >> v >> e >> s ;
    int goal ; cin >> goal ;
    vector<int> start(s,0);
    for (size_t i = 0; i < s; i++) {
        cin >> start[i] ;
    }
    map<int,vector<pair<int,int>>> rpath ;
    for (size_t i = 0; i < e; i++)
    {
        int from , to ,weight ; cin >> from >> to >> weight ;
        rpath[to].push_back({from,weight});
    }
    vector<int> val(v,inf) ;
    for (size_t i = 0; i < s; i++)
    {
        val[start[i]] = 0 ;
    }
    for (size_t k = 1; k <= v-1; k++)
    {
        for (size_t j = 0; j < v; j++)
        {
            int node = j ;
            for (auto [prev,w] : rpath[node])
            {
                if (val[prev] != inf && val[prev] + w < val[node]){
                    val[node] = val[prev] + w ;
                }
            }
        }
    }
    cout << val[goal] ;
}







// #include <bits/stdc++.h>

// using namespace std ;
// const int inf = 1e9 ;
// int main(){

//     int v , e, s ; cin >> v >> e >> s ;
//     int goal ; cin >> goal ;
//     vector<int> start(s,0);
//     for (size_t i = 0; i < s; i++)
//     {
//         cin >> start[i];
//     }
//     vector<int> row(v,inf);
//     vector<vector<int>> grid(v,row);
//     for (size_t i = 0; i < v; i++)
//     {
//         grid[i][i] = 0 ;
//     }
//     for (size_t i = 0; i < e; i++)
//     {
//         int x , y ,weight; cin >> x >> y >> weight;
//         grid[x][y] = weight ;
//     }
    
//     for (size_t k = 0; k < v; k++)
//     {
//         for (size_t i = 0; i < v; i++)
//         {
//             for (size_t j = 0; j < v; j++)
//             {
//                 if (grid[i][k] != inf && grid[k][j] != inf && grid[i][j] > grid[i][k] + grid[k][j]) {
//                     grid[i][j] = grid[i][k] + grid[k][j] ;
//                 }
//             }
            
//         }
//     }
//     int minval = INT_MAX ;
//     for (size_t i = 0; i < s; i++)
//     {
//         minval = min (minval,grid[start[i]][goal]);
//     }
//     cout << minval ;
// }