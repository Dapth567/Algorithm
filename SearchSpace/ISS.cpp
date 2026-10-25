#include <bits/stdc++.h>
using namespace std ;
int ans = 0 ;
void iss(int last_val , int total, int& goal){
    if (total == goal) {
        ans++ ; return;
    }
    for (size_t i = last_val ; i <= goal - total; i++) {
        iss(i,total+i,goal);
    }
}
int main() {
    int n ; cin >> n ;
    iss(1,0,n) ;
    cout << ans ;
}