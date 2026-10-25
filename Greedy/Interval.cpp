#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n ;
    cin >> n ;
    vector<int> s(n) , f(n) ;
    for (size_t i = 0; i < n; i++) {
        cin >> s[i] ;
    }
    for (size_t i = 0; i < n; i++) {
        cin >> f[i] ;
    }
    vector<pair<int,int>> order(n) ;
    for (size_t i = 0; i < n; i++) {
        order[i] = {f[i],s[i]} ;
    }
    sort(order.begin(),order.end());
    for (size_t i = 0; i < n; i++)
    {
        s[i] = order[i].second ;
        f[i] = order[i].first ;
    }
    
    int last_select = -1 ,count = 0 ;
    for (size_t i = 0; i < n; i++)
    {
        if (s[i] >= last_select) {
            count++;
            last_select = f[i] ;
        }
    }
    cout << count ;
}