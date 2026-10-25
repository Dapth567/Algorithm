#include <bits/stdc++.h>
using namespace std ;
int main() {
    int t,c,ct ;
    cin >> t >> c ;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (int i = 0; i < t; i++) {
        cin >> ct ;
        pq.push({0,ct});        
    }
    for (int i = 0; i < c; i++) {
        auto [x,ct] = pq.top() ; pq.pop() ;
        cout << x << "\n";
        pq.push({x + ct,ct});        
    }
}