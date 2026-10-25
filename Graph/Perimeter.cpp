#include <bits/stdc++.h>

using namespace std ;

// void create_path(set<pair<int,int>> used_road, map<int,vector<int>> graph, int vertice,int& goal,vector<int>& visit){
//     if (used_road.size() == goal){
//         visit[vertice]++;
//         return ;
//     }
//     for (auto v : graph[vertice])
//     {
//         set<pair<int,int>> copy_used_road = used_road ;
//         int begin = vertice , next = v ;
//         if (begin > next){
//             swap(begin,next);
//         }
//         if (copy_used_road.find({begin,next}) == copy_used_road.end()){
//             // cout << "blocking " << begin << " & " << next << "\n";
//             copy_used_road.insert({begin,next});
//             create_path(copy_used_road,graph,v,goal,visit);
//         }
//     }
// }

int main () {
    set<int> ans_size ;
    map<int,vector<int>> graph ;
    vector<int> null ;
    set<pair<int,int>> used_road;
    int v ,e ,k ,a ,b ;
    cin >> v >> e >> k ;
    vector<int> visit(v+1,0);
    for (size_t i = 0; i <= v; i++)
    {
        graph[i] = null ;
    }
    
    for (size_t i = 0; i < e; i++)
    {
        cin >> a >> b ;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // create_path(used_road,graph,0,k,visit);
    set<pair<int,int>> order ;
    order.insert({0,0}) ; //placeing step and start
    visit[0] = true ;
    while (!order.empty())
    {
        auto it = order.begin() ;
        if (it->first == k) {
            ans_size.insert(it->second);
        } else {
            for (auto v : graph[it->second])
            {
                if (!visit[v]){
                    visit[v] = true ;
                    order.insert({(it->first)+1,v});
                }
            }               
        }
        order.erase(it);
    }
    // for (auto num : ans_size)
    // {
    //     cout << num << " " ;
    // }
    
    cout << ans_size.size() ;
}