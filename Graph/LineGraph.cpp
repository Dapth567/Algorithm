#include <bits/stdc++.h>

using namespace std ;

bool create_line(vector<bool>& visit,int vertice,int parent,map<int,vector<int>>& graph,bool& error){
    
    visit[vertice] = true ;

    
    if (graph[vertice].size() > 2 ){
        error = true ;
    }
    
    for (auto v : graph[vertice])
    {
        if (visit[v] == true && parent != v){
            error = true ;
        } 
        if(visit[v] == false){
            bool dummy;
            dummy = create_line(visit,v,vertice,graph,error);
        }
    }
    return error ;
}

int main(){
    int v, e, a, b, count = 0;
    bool error = false;
    cin >> v >> e;
    map<int,vector<int>> graph;
    vector<bool> visit(v,false);
    vector<int> null;
    for (size_t i = 0; i < v; i++)
    {
        graph[i] = null;
    }
    for (size_t i = 0; i < e; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (size_t i = 0; i < v; i++)
    {
        if (visit[i] == false){
            error = false ;
            if (!create_line(visit,i,-1,graph,error)){
                count++;
            }
        }
    }
    cout << count ;
    
}