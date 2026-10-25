#include <bits/stdc++.h>

using namespace std ;
int const inf = 1e9 ;
int main(){
    int n , s ; cin >> n >> s ; 
    vector<int> t(n+1,inf) ;
    t[1] = 0 ;
    map<int,vector<pair<int,int>>> path ;
    for (size_t i = 0; i < s; i++) {
        int u , v , w ; 
        cin >> u >> v >> w ;
        path[u].push_back({v,w});
        path[v].push_back({u,w});
    }
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>>  pq ; // time & pos
    pq.push({0,1});
    while (!pq.empty()) {
        auto [time,u] = pq.top() ; pq.pop() ;
        for (auto [v,w] : path[u]){
            if (t[v] > t[u] + w){
                t[v] = t[u] + w ;
                pq.push({t[v],v}) ;
            }
        }
    }
    int max_val = 0 ;
    for (size_t i = 2; i <= n ; i++){ max_val = max(max_val, t[i]); }
    for (size_t i = 2; i <= n ; i++){ cout << abs(max_val - t[i]) << "\n" ;}
    
    
}