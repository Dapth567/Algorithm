#include <bits/stdc++.h>

using namespace std ;

void cal_cyc_size(int& cyc_size,int vertice,int parent,int step,vector<int> visit, map<int,vector<int>>& graph){
    if (cyc_size == -1){
        step++;
        visit[vertice] = step ;
        for (auto v : graph[vertice])
        {
            if (visit[v] >= 0 && v != parent){
                cyc_size = abs(visit[v]-visit[vertice]) + 1;
                break;
            } else if(visit[v] == -1){
                cal_cyc_size(cyc_size,v,vertice,step,visit,graph);
            }
        }
    }
}

int main() {

    int n , a , b ,cyc_size = -1;
    map<int,vector<int>> graph ;
    vector<int> null ;
    cin >> n ;
    vector<int> visit(n,-1) ;
    for (size_t i = 0; i < n; i++)
    {
        graph[i] = null ;
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> a >> b ;
        graph[a].push_back(b) ;
        graph[b].push_back(a) ;
    }
    cal_cyc_size(cyc_size,0,-1,-1,visit,graph);
    cout << cyc_size ;
}