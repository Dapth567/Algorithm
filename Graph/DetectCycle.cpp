#include <bits/stdc++.h>

using namespace std ;

bool DetCyc(int vertice,vector<bool> visit,int parent,map<int,vector<int>>& graph){
    bool ans ;
    visit[vertice] = true ;
    for (auto v : graph[vertice])
    {
        if (visit[v] == true && parent != v){
            return true ;
        } else if (visit[v] == false){
            ans = DetCyc(v,visit,vertice,graph);
            if (ans == true ){
                return true ;
            }
        }
    }
    return false ;
}


int main () {
    int n , v , e , a , b ;
    cin >> n ;
    for (size_t i = 0; i < n; i++){

        cin >> v >> e ;
        map<int,vector<int>> graph ;
        vector<bool> visit(v,false);
        vector<int> null ;

        for (size_t i = 0; i < v; i++)
        {
            graph[i] = null ;
        }

        for (size_t i = 0; i < e; i++)
        {
            cin >> a >> b ;
            if (a != b){
                graph[a].push_back(b);
                graph[b].push_back(a);             
            }
        }

        bool ans = false ;
        for (size_t i = 0; i < visit.size() ; i++)
        {
            if (visit[i] == false){
                ans = DetCyc(i,visit,-1,graph);
                if (ans) {
                    break ; 
                }
            }            
        }

        if (ans){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
}