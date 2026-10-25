// #include <bits/stdc++.h>

// using namespace std ;



// void dfs(int vertice,vector<bool>& visited,map<int,vector<int>>& cc){
//     if (visited[vertice-1]){
//         return ;
//     } else {
//         visited[vertice-1] = true ;
//     }
    
//     for (auto num : cc[vertice])
//     {
//         dfs(num,visited,cc);
//     }
// }

// int main() {
//     int v , e ;
//     cin >> v >> e ;
//     vector<bool> visit(v,false) ;
//     vector<int> null ;
//     map<int,vector<int>> cc ;
//     int count = 0 ;

//     for (size_t i = 1; i <= v; i++)
//     {
//         cc[i] = null ;
//     }

//     int a,b ;
//     for (size_t i = 0; i < e; i++)
//     {
//         cin >> a >> b ;
//         cc[a].push_back(b);
//         cc[b].push_back(a);
//     }

//     for (size_t i = 1; i <= v; i++)
//     {
//         if (visit[i-1] == false){
//             count++;
//             dfs(i,visit,cc) ; 
//         }
//     }
//     cout << count ;
    

// }

#include <bits/stdc++.h>

using namespace std ;

map<int,vector<int>> graph ;

void dfs(vector<int>& visit,int& cc , int v){
    visit[v] = cc ;
    for (auto to : graph[v])
    {
        if (visit[to] == -1){
            dfs(visit,cc,to);
        }
    }
}

int main(){
    int v,e,cc = 0 ; cin >> v >> e;
    vector<int> visit(v+1,-1) ;
    for (size_t i = 0; i < e; i++)
    {
        int from,to ; cin >> from >> to ;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for (size_t i = 1; i <= v; i++)
    {
        if(visit[i] == -1){
            cc++;
            dfs(visit,cc,i);
        }
    }
    cout << cc ;
    
}