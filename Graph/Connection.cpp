#include <bits/stdc++.h>
using namespace std;
int main (){
    int n ,m,k,start,stop,count,ans =INT_MIN; 
    cin >> n >> m>> k;
    map<int,vector<int>> map ;
    vector<int> nul ;
    for (size_t i = 0; i < n; i++)
    {
        map[i] = nul ;
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> start >> stop ;
        map[start].push_back(stop);
        map[stop].push_back(start);
    }
    queue<pair<int,int>> order ;
    for (size_t i = 0; i < n; i++)
    {
        vector<bool> visit(n,false) ;
        count = 1 ;
        visit[i] = true ;
        order.push({i,0});
        while (!order.empty())
        {
            int v = order.front().first , step = order.front().second;
            for (auto adj : map[v])
            {
                if (!visit[adj] && step + 1 <= k){
                    count++;
                    visit[adj] = true ;
                    order.push({adj,step+1});
                }
            }
            order.pop();
        }
        ans = max (ans,count);
    }
    cout << ans ;
}