#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n , m , k ,server , start ,stop,time,max_time= INT_MIN;
    cin >> n >> m >> k ;
    map<int,vector<int>> link_cable ;
    vector<int> time_duration(n,0) , null ;
    set<pair<int,int>> time_order;  //start time and server
    vector<bool> visit(n,false) ;
    for (size_t i = 0; i < k; i++)
    {
        cin >> server ;
        time_order.insert({0,server});
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> time_duration[i];
        link_cable[i] = null ;
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> start >> stop ;
        link_cable[start].push_back(stop);
        link_cable[stop].push_back(start);
    }
    while (time_order.size() != 0)
    {
        auto it = time_order.begin();
        start = it->first ;
        server = it->second ;
        if (!visit[server]){
            time = start + time_duration[server];
            visit[server] = true ;
            max_time = max(max_time,time);
            // cout << "server " << server << " got hacked" << " at time " << time << "\n" ;
            for (auto v : link_cable[server])
            {
                if (visit[v] == false) {
                    time_order.insert({time,v}) ;
                }
            }            
        }
        time_order.erase(it);
    }
    cout << max_time ;
    
    
    
    
}