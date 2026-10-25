#include <bits/stdc++.h>

using namespace std ;

void gennum(vector<int> v,int& n ,int count,int& m){

    if(count == n ){
        for (size_t i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
        return ;
    }

    if(count == 0){
        for (size_t i = 1; i <= m; i++)
        {
            v[count] = i ;
            gennum(v,n,count+1,m);
        }   
        return ;
    } else if(count == 1){
        for (size_t i = 1; i <= m; i++)
        {
            if(v[count-1] != i){
                v[count] = i ;
                // cout << "gen " << i << " after" << v[count-1] << "\n" ;
                gennum(v,n,count+1,m);
            }
        }

    } else {
        if(v[count-1] > v[count-2]){
            for (size_t i = 1; i < v[count-1]; i++)
            {
                v[count] = i ;
                gennum(v,n,count+1,m);
            }
        } else {
            for (size_t i = v[count-1]+1 ; i <= m; i++)
            {
                v[count] = i ;
                gennum(v,n,count+1,m);
            }            
        }
    }

}

int main() {
    int n,m ;
    cin >> n >> m ;
    vector<int> v(n,0);
    gennum(v,n,0,m);
}