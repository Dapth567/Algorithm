#include <bits/stdc++.h>
// longets path in dag
using namespace std ;
void dfs(vector<int>& deg_in, int pos,vector<int>& dist,map<int,vector<pair<int,int>>>& path,vector<bool>& visit){
    visit[pos] = true ;
    for (auto [v,w] : path[pos]) {
        dist[v] = max(dist[pos] + w , dist[v]) ;
        deg_in[v]--;
        if (deg_in[v] == 0 && visit[v] == false){
            dfs(deg_in,v,dist,path,visit) ;
        }
    }
}

int main(){
    int n , m ; cin >> n >> m ;
    map<int,vector<pair<int,int>>> path ;
    vector<int> deg_in(n+1,0),dist(n+1,0);
    vector<bool> visit(n+1,false) ;
    for (size_t i = 0; i < m; i++){
        int u , v , w ;
        cin >> u >> v >> w ;
        deg_in[v]++;
        path[u].push_back({v,w});
    }
    for (size_t i = 1; i <= n; i++) {
        if (deg_in[i] == 0 && visit[i] == false){
            dfs(deg_in,i,dist,path,visit);
        }
    }
    int max_val  = 0;
    for (size_t i = 1; i <= n; i++)
    {
        max_val = max(max_val,dist[i]) ;
    }
    cout << max_val  ;
    
}