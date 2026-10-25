// #include <bits/stdc++.h>

// using namespace std ;
// int ans = 0 ;
// bool check(vector<int>& board,int place,int& pos){
//     for (int i = 0; i < pos; i++)
//     {
//         if (abs(pos - i) == abs(place - board[i])){
//             return false ;
//         }
//     }
//     return true ;
// }

// void cal_queen(vector<int> board,set<int> used){
//     int n = board.size() ;
//     int m = used.size() ;
//     if (n == m) {
//         ans++;
//         return ;
//     }
//     for (int i = 0; i < n; i++) {
//         if (used.find(i) == used.end() && check(board,i,m)){
//             vector<int> cop_board(board);
//             set<int> cop_set(used);
//             cop_set.insert(i);
//             cop_board[m] = i ;
//             cal_queen(cop_board,cop_set);
//         }
//     }
    
// }

// int main(){
//     int n ; cin >> n ;
//     vector<int> board(n) ;
//     set<int> used ;
//     cal_queen(board,used) ;
//     cout << ans ;
// }

#include <bits/stdc++.h>
//Quickest code belong to Wongchat 
using namespace std;
int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,m,s,t; cin >> n >> m >> s >> t;
    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0;i < m;i++){
        int a,b,w; cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }
    vector<int> city(n+1,-1e8);
    city[s] = 0;
    for(int i = 1;i <= n;i++){
        for(auto edge : adj[i]){
            int u = i;
            int v = edge.first;
            int w = edge.second;
            if( city[v] < city[u] + w) {
                city[v] = city[u] + w;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(auto edge : adj[i]){
            int u = i;
            int v = edge.first;
            int w = edge.second;

            if( city[v] < city[u] + w) {
                cout << "INFINITY" ;
                return 0;
            }
        }
    }
    cout << city[t] ;
}