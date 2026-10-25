#include <bits/stdc++.h>

using namespace std ;
const int inf = 1e9 ;
int main(){
    int n , m , s; cin >> n >> m >> s;
    map<int,vector<pair<int,int>>> path ;
    int dist[n+1] ;
    set<pair<int,int>> order ;
    for (size_t i = 1; i <= n; i++) {
        if (i != s){
            dist[i] = inf ;
        } else {    
            dist[i] = 0 ;
            order.insert({0,i});
        }
    }
    for (size_t i = 0; i < m; i++) {
        int a , b , w ; cin >> a >>b >> w ;
        path[a].push_back({b,w});
    }
    while (!order.empty()) {
        auto [t,u] = *(order.begin());
        order.erase(order.begin());
        for (auto [v,w] : path[u])
        {
            if (dist[v] > dist[u] + w ){
                dist[v] = dist[u] + w ;
                order.insert({dist[v],v});
            }
        }
        
    }
    for (size_t i = 1; i <= n ; i++) {
        cout << dist[i] << " ";
    }
}