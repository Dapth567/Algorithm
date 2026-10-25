#include <bits/stdc++.h>

using namespace std ;
map<pair<int,int>,int> c_func ;
int C(int n ,int k){

    if (n == k || k == 0){
        return 1 ;
    }

    if(c_func.find({n,k}) == c_func.end()){
        c_func[{n,k}] = C(n-1,k-1) + C(n-1,k) ;
        return c_func[{n,k}] ;
    } else {
        return c_func[{n,k}];
    }
}

int main() {
    int n,k;
    cin >> n >> k ;
    cout << C(n,k) ;
}