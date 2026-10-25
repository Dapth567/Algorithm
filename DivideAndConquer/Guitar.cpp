#include <bits/stdc++.h>

using namespace std ;

bool x_legit(vector<int>& v,int  level ,int  start,int  last){
    for (size_t i = start ; i <= last ; i++)
    {
        if (v[i] != level){
            return false ;
        }
    }
    return true ;
}

bool arr_legit(vector<int>&v ,int level ,int start , int stop){
    if(start == stop){
        return v[start] == level ;
    }
    int m = (start+stop)/2 ;
    bool left_side = x_legit(v,level,start,m);
    bool right_side = x_legit(v,level,m+1,stop);
    if(left_side){
        return arr_legit(v,level+1,m+1,stop);
    }
    if(right_side){
        return arr_legit(v,level+1,start,m);
    }
    return false ;
}

//guitar
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    size_t t ;
    cin >> t ;
    while(t--){
        int k, level ;
        cin >> k >> level ;
        vector<int> arr (pow(2,k));
        for (size_t i = 0; i < pow(2,k); i++)
        {
            cin >> arr[i] ;
        }
        if (arr_legit(arr,level,0,arr.size()-1)){
            cout << "YES\n" ;
        } else {
            cout << "NO\n" ;
        }
        
    }
}
