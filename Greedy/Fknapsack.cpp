#include <bits/stdc++.h>

using namespace std ;

void fknap(int idx , vector<float>& pick , float remain , float& sum_value,vector<float>& v , vector<float>& w){
    if (idx == 0 || remain == 0) {
        return ;
    }
    if (remain >= w[idx]) {
        pick[idx] = 1 ;
        sum_value += v[idx];
        fknap(idx-1,pick,remain-w[idx],sum_value,v,w) ;
    } else {
        pick[idx] = remain / w[idx] ;
        sum_value += (v[idx] * pick[idx]) ;
        fknap(idx-1,pick,0,sum_value,v,w) ;
    }
}

int main() {
    float sum_value = 0 ;
    float goal ; cin >> goal ;
    int n ; cin >> n ;
    vector<float> v(n),w(n) ;
    vector<tuple<float,float,float>> order(n) ;
    for (size_t i = 0; i < n; i++) {
        cin >> v[i] ;
    }
    for (size_t i = 0; i < n; i++) {
        cin >> w[i] ;
        order[i] = {v[i]/w[i],v[i],w[i]} ;
    }
    sort(order.begin(),order.end()) ;
    for (size_t i = 0; i < n; i++) {
        auto [x , val , wei] = order[i] ;
        v[i] = val ; w[i] = wei ; 
    }
    vector<float> pick(n,0);
    fknap(n-1,pick,goal,sum_value,v,w);
    cout << sum_value ;
}