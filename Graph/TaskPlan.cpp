#include <bits/stdc++.h>
using namespace std ;
void cal(map<int,vector<int>>& graph,vector<int>& deg_in,int vertice,vector<int>& pos,vector<bool>& visit){
    if (deg_in[vertice] == 0 && !visit[vertice]){
        visit[vertice] = true ;
        cout << vertice << " " ;
        for (int v : graph[vertice]){
            deg_in[v]--;
            cal(graph,deg_in,v,pos,visit);
        }
    }
}
int main() {
    int n ,pre_task,from_value;
    cin >> n ;
    vector<int> deg_in(n,0),posisble;
    vector<bool> visit(n,false);
    map<int,vector<int>> graph ;
    for (size_t i = 0; i < n; i++){
        cin >> pre_task ;
        for (size_t j = 0; j < pre_task; j++){
            cin >> from_value ;
            graph[from_value].push_back(i);
            deg_in[i]++;
        }
    }
    for (size_t i = 0; i < n; i++){
        cal(graph,deg_in,i,posisble,visit);
    }
}