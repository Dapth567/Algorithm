#include <bits/stdc++.h>

using namespace std ;

void burn(int target,map<int,vector<int>>& firelink,vector<int>& grass_beauty,int& total){
    total -= grass_beauty[target];
    grass_beauty[target] = 0 ;
    if (firelink[target].size() > 0){
        for (auto v : firelink[target])
        {
            if (grass_beauty[v] != 0){
                burn(v,firelink,grass_beauty,total);
            }
        }
    }    
}

int main() {
    int n, m, k, a, c, total = 0;
    cin >> n >> m >> k ; //จน v , e , อันท้ายคือวัน 

    vector<int> b(n) ;
    for (size_t i = 0; i < n; i++) //ความสวยงามแต่ละทุงหญ้า
    {
        cin >> b[i] ;
        total += b[i];
    }

    vector<int> fire(k);
    for (size_t i = 0; i < k; i++) //หมายเลขทุ่งที่จะไหม้รายวัน
    {
        cin >> fire[i] ;
    }

    map<int,vector<int>> firelink ;  //จับคู่ทุ่งไหม้แบบ directed
    vector<int> null ;
    for (size_t i = 0; i < n; i++)
    {
        firelink[i] = null ;
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> a >> c ;
        firelink[a].push_back(c);
    }
    
    for (size_t i = 0; i < k; i++)
    {
        int target = fire[i] ;
        burn(target,firelink,b,total) ;
        cout << total << " ";
    }
}