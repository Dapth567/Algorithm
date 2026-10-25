#include <bits/stdc++.h>

using namespace std ;

size_t mod_expo(size_t x , size_t n , size_t k){


    if (n == 1) {
        return x % k ;
    }
    if (n == 0){
        return 1 ;
    }

    if (n % 2 == 0){
        return (mod_expo(x,n/2,k) * mod_expo(x,n/2,k))%k ;
    } else {
         return ((mod_expo(x,n/2,k) * mod_expo(x,n/2,k))%k  * mod_expo(x,1,k))%k ;
    }
}

int main() {
    size_t x , n , k ,ans;
    cin >> x >> n >> k ;
    ans = mod_expo(x,n,k);
    cout << ans ;
}