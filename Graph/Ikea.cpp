#include <bits/stdc++.h>

using namespace std ;

int main() {
    int v , e ,start,stop;
    cin >> v >> e ;
    vector<int> in_deg(v+1,0),null ;
    map<int,vector<int>> graph ;
    for (size_t i = 1; i <= v; i++)
    {
        graph[i] = null ;
    }
    
    for (size_t i = 0; i < e; i++)
    {
        cin >> start >> stop ;
        graph[start].push_back(stop);
        in_deg[stop]++;
    }
    for (size_t i = 0; i < 5; i++)
    {
        vector<int> cop_in_deg(in_deg) ;
        vector<int> step(v,0);
        bool pass = true ;        
        for (size_t j = 0; j < v; j++)
        {
            cin >> step[j];
        }

        for (size_t j = 0; j < v; j++)
        {
            if (cop_in_deg[step[j]] != 0){
                pass = false ;
                break;
            }
            for (auto vertice : graph[step[j]])
            {
                cop_in_deg[vertice]--;
            }
        }
        if (pass){
            cout << "SUCCESS\n";
        } else {
            cout << "FAIL\n";
        }
        
        
    }
    
    
}