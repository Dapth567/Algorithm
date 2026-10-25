#include <bits/stdc++.h>

using namespace std ;

void binary_search2(vector<int>& v , int start , int stop , int& value){
    if (start == stop){
        if (v[start] > value){
            if (start == 0){
                cout << -1 << endl;
            }else {
                cout << v[start-1] << endl; 
            }
        } else {
            cout << v[start] << endl;
        }
        return ;
    }

    int m = (start+stop) / 2 ;
    if (v[m] == value){
        cout << value << endl ;
        return ;
    } else if (value < v[m]) {
        binary_search2(v,start,m,value);
    } else {
        binary_search2(v,m+1,stop,value);
    }

}

int main() {
    int n , m ,value;
    vector<int> v ;
    cin >> n >> m ;

    for (size_t i = 0; i < n; i++)
    {
        cin >> value ;
        v.push_back(value) ;
    }

    for (size_t i = 0; i < m; i++)
    {
        cin >> value ;
        binary_search2(v,0,v.size()-1,value) ;
    }
    
    
}