#include <bits/stdc++.h>

using namespace std ;

int main(){
    float w ; cin >> w ;
    int n ; cin >> n ;
    vector<float> v(n) , kg(n) ;
    for (size_t i = 0; i < n; i++) {
        cin >> v[i] ;
    }
    for (size_t i = 0; i < n; i++) {
        cin >> kg[i] ;
    }
    vector<pair<float,float>> order(n) ;
    for (size_t i = 0; i < n; i++) {
        order[i] = {kg[i],v[i]} ;
    }
    sort(order.begin(),order.end()) ;
    for (size_t i = 0; i < n; i++) {
        kg[i] = order[i].first ;
        v[i] = order[i].second ;
    }
    vector<float> heuristic(n+1,0) ;
    heuristic[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--) {
        heuristic[i] = heuristic[i+1]+v[i] ;
    }
    priority_queue<tuple<float,int,float,float>> pq ; // heuristic , index , totalweight , totalval
    float max_val = 0 ;
    pq.push({heuristic[0],0,0,0});
    while (!pq.empty()) {
        auto [h,idx,tw,tv] = pq.top() ; pq.pop() ;
        max_val = max(max_val,tv);
        if (idx == n || tv+heuristic[idx+1] < max_val){
            continue;
        }
        if (tw + kg[idx] <= w) {
            pq.push({tv+v[idx]+heuristic[idx+1],idx+1,tw+kg[idx],tv+v[idx]}) ;
        }
        pq.push({tv+heuristic[idx+1],idx+1,tw,tv});
    }
    cout << max_val ;
}