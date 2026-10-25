#include <bits/stdc++.h>

using namespace std ;

int ans = INT_MIN ;

void create_line(map<int,vector<int>>& graph, vector<int>& in_deg,vector<bool>& visit, int vertice,vector<int>& value,vector<int>& mini){
    visit[vertice] = true ;
    for (auto v : graph[vertice])
    {
        if (visit[v] == false){
            ans = max(ans,value[v] - mini[vertice]) ;
            in_deg[v]--;
            mini[v] = min(mini[vertice],mini[v]);
            if (in_deg[v] == 0){
                create_line(graph,in_deg,visit,v,value,mini);
            }            
        }
    }
}

int main() {
    int v, e, a, b ;
    cin >> v >> e ;
    vector<int> value(v) , in_deg(v,0) , mini(v);
    vector<bool> visit(v,false);
    map<int,vector<int>> graph ;
    for (size_t i = 0; i < v; i++)
    {
        cin >> value[i] ;
    }
    mini = value ; 
    for (size_t i = 0; i < e; i++)
    {
        cin >> a >> b ;
        in_deg[b]++ ;
        graph[a].push_back(b) ;
    }
    for (size_t i = 0; i < v; i++)
    {
        if (in_deg[i] == 0 && visit[i] == false){
            mini[i] = value[i] ;
            create_line(graph,in_deg,visit,i,value,mini);
        }
    }
    cout << max(0,ans) ;
}