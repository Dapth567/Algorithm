#include <bits/stdc++.h>

using namespace std ;

int main (){
    int n , m , value , count = 0;
    map<int,int> M ;
    cin >> n >> m ;
    while (n--)
    {
        cin >> value ;
        M[value] = count ;
        count++ ;
    }
    
    while (m--)
    {
        cin >> value ;
        auto it = M.upper_bound(value);
        if (it == M.begin()) {
            cout << -1 << endl;
        } else {
            it-- ;
            cout << it->second << endl;
        }
    }
}

// void BSearch3(int start,int stop , int& value, vector<int> v){
//     if (start == stop){
//         if (v[start] > value){
//             cout << start-1 << endl;
//         } else {
//             cout << start << endl;
//         }
//         return ;
//     }
//     int idx = (start+stop) / 2 ;
//     if (v[idx] > value ){
//         BSearch3(start,idx,value,v);
//     } else {
//         BSearch3(idx+1,stop,value,v);
//     }
// }

// int main() {
//     vector<int> v ;
//     int n , m ,value ;
//     cin >> n >> m ;
//     while (n--)
//     {
//         cin >> value ;
//         v.push_back(value);
//     }
//     while (m--)
//     {
//         cin >> value ;
//         if(v[0] > value ){
//             cout << -1 << endl;
//         } else if (v[v.size()-1] <= value){
//             cout << v.size()-1 << endl;
//         } else {
//             BSearch3(0,v.size()-1,value,v);
//         }   
//     }
// }