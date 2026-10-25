// #include <bits/stdc++.h>

// using namespace std ;
// int main() {
//     std::ios_base::sync_with_stdio(false); std::cin.tie(0);

//     int n , max_deg = 0 , maxi = 0 ;
//     map<int,int> deg_count ;
//     deg_count[0] = 0 ;

//     cin >> n ;
//     int table[n][n] = {0};

//     for (size_t i = 0; i < n; i++)
//     {
//         max_deg = 0 ;
//         for (size_t j = 0; j < n; j++)
//         {
//             cin >> table[i][j] ;
//             if (table[i][j]){
//                 max_deg++;
//             }
//         }
//         maxi = max(maxi,max_deg);
//         if (deg_count.find(max_deg) == deg_count.end()){
//             deg_count[max_deg] = 1 ;
//         } else {
//             deg_count[max_deg] += 1 ;
//         }
//     }

//     for (size_t i = 0; i <= maxi; i++)
//     {
//         if (deg_count.find(i) == deg_count.end()){
//             cout << "0 ";
//         } else {
//             cout << deg_count[i] << " " ;
//         }
//     }
// }
#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n ; cin >> n ;
    int max_total = 0  ;
    map<int,int> count ;
    for (size_t i = 0; i < n; i++)
    {
        count[i] = 0 ;
    }
    
    for (size_t i = 0; i < n; i++)
    {
        int total = 0 ;
        for (size_t j = 0; j < n; j++)
        {
            int value ;cin >> value ;
            if (value) {
                total++;
            }
            
        }
        count[total]++;
        max_total = max(max_total,total);
    }
    for (size_t i = 0; i <= max_total; i++)
    {
        cout << count[i] << " ";
    }
    
}
