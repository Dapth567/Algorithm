#include <bits/stdc++.h>

using namespace std ;

int main(){
    int n , weight;
    cin >> n ;
    map<int,vector<pair<int,int>>> path ;
    vector<int> visit(n,false) ;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> weight ;
            if (i == j) {
                continue;
            }
            if (weight == -1) {
                continue;   
            } 
            path[i].push_back({j,weight});
        }
    }
    set<pair<int,int>> shortest_path ;
    int distance ,city,next_dist,min_dist= INT_MIN,visit_count = 0;
    shortest_path.insert({0,0}); // alarm and city
    while (!shortest_path.empty())
    {
        auto it = shortest_path.begin() ;
        distance = it->first ;
        city = it->second ;
        if (!visit[city]){
            visit[city] = true ;
            visit_count++;
            min_dist = max(min_dist,distance);
            for (auto v : path[city])
            {
                if (!visit[v.first]) {
                    // cout << "next dis = " << distance << " + " << v.second << "\n" ;
                    next_dist = distance + v.second;
                    shortest_path.insert({next_dist,v.first});
                }
            }
        }
        shortest_path.erase(it);
    }
    if (visit_count != visit.size()){
        cout << -1 ;
    } else {
        cout << min_dist ;
    }
    

    
}