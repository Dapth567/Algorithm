// #include <bits/stdc++.h>

// using namespace std ;

// int cal_heu(vector<vector<int>> rubik,string& moves,vector<vector<int>>& sol){
//     int n = rubik.size() ;
//     int m = sol.size() ;
//     for (size_t i = 0; i < m; i++)
//     {
//         for (size_t j = 0; j < m; j++)
//         {
            
//         }
        
//     }
    
// }

// int main() {
//     int n ; cin >> n ;
//     vector<vector<int>> rubik(n,vector<int> (n)) , sol(n-2,vector<int> (n-2));
//     set<vector<vector<int>>> found_pattern ;
//     for (size_t i = 0; i < n; i++) {
//         for (size_t j = 0; j < n; j++) {
//             cin >> rubik[i][j] ;
//         }
//     }
//     for (size_t i = 0; i < n-2; i++) {
//         for (size_t j = 0; j < n-2; j++) {
//             cin >> sol[i][j] ;
//         }
//     }
// }

#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n , m ; cin >> n >> m ;
    map<int,int> graph ;
    for (size_t i = 0; i < n; i++)
    {
        int to , from ; cin >> to >> from ;
        if (graph.find(from) == graph.end()){
            graph[from] = 1 ;
        } else {
            graph[from]++;
        }
    }
    for (auto [v,u] : graph)
    {
        cout << v << ": " << u << "\n";
    }
    
}