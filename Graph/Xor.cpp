#include <bits/stdc++.h>

using namespace std ;

// int find_xor_value(int a,int b){
//     int count = 0 ,two_pow = 0;
//     if (b > a){
//         swap(a,b);
//     }
//     while(true){
//         if (a / pow(2,two_pow) > 0){
//             two_pow++;
//         } else {
//             break;
//         }
//     }
//     for (size_t i = 0; i < two_pow; i++)
//     {
        
//     }
    
//     return count ;
// }

int parent(vector<int>& disj,int a){
    while (disj[a] != -1)
    {
        a = disj[a];
    }
    return a ;
}

void merge(int a, int b ,vector<int>& disj){
    a = parent(disj,a);
    b = parent(disj,b);
    if (a == b){
        return ;
    } else {
        disj[b] = a ;
    }
}

int main(){
    long long n ,total = 0; cin >> n ;
    vector<int> each_val(n,0) ,disj(n,-1);
    vector<tuple<int,int,int>> edge ;
    for (size_t i = 0; i < n; i++)
    {
        cin >> each_val[i];
        for (int j = i - 1; j >= 0 ; j--)
        {
            // cout << each_val[i]  << " xor " << each_val[j] << " = " << find_xor_value(each_val[i],each_val[j]) << "\n";
            edge.push_back({each_val[i]^each_val[j],i,j}) ;
        }
    }
    sort(edge.begin(),edge.end());
    reverse(edge.begin(),edge.end());
    for (auto [w,u,v] : edge)
    {
        if (parent(disj,u) != parent(disj,v)){
            merge(u,v,disj);
            total += w ;
        }
    }
    cout << total ;
}