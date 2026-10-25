#include <bits/stdc++.h>

using namespace std ;

void pareto(int n ,int& l ,int& r ,int& ans,int& count){

    if (count > r){
        return ;
    }

    if (n == 0 || n == 1){
        if (count >= l){
           ans += n; 
        }
        count++;
        return ;
    }
    
    pareto(n/2,l,r,ans,count);
    pareto(n%2,l,r,ans,count);
    pareto(n/2,l,r,ans,count);    
    

}

int main() {
    int n,l,r,ans = 0,count = 1;
    cin >> n >> l >> r ;
    pareto(n,l,r,ans,count) ;
    cout << ans ;
}