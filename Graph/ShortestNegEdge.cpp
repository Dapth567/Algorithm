// #include <bits/stdc++.h>

// using namespace std ;

// const int inf = 1e9;

// int main(){
//     int v, e ,s ; cin >>v >> e >> s ;
//     vector<int> val(v,inf) ;
//     map<int,vector<pair<int,int>>> rev_p ;
//     val[s] = 0 ;
//     for (size_t i = 0; i < e; i++)
//     {
//         int from , to , w ; cin >> from >> to >> w ;
//         rev_p[to].push_back({from,w});
//     }
//     for (size_t i = 1; i <= v-1 ; i++)
//     {
//         for (size_t j = 0; j < v; j++)
//         {
//             int node = j ;
//             for (auto [prev,w] : rev_p[node])
//             {
                
//                 if (val[prev] != inf && val[prev] + w < val[node]) {
//                     val[node] = val[prev] + w ;
//                 }
//             }
//         }
//     }
//     bool found = false ;
//     for (size_t i = 0; i < v; i++)
//     {
//         int node = i ;
//         for (auto [prev,w] : rev_p[node])
//         {
//             if (val[prev] != inf && val[prev] + w < val[node]) {
//                 found = true;
//                 break;
//             }
//         }
//         if (found) break;
//     }
//     if (found){
//         cout << -1 ;
//     } else {
//     for (auto row : val)
//     {
//         cout << row << " " ;
//     }
//     }

    
// }

#include <bits/stdc++.h>
using namespace std ;
const int inf = 1e9 ;
 int main() {
    int v , e , s ; cin >> v >> e >> s ;
    int floyd[v][v] ;
    for (size_t i = 0; i < v; i++) {
        for (size_t j = 0; j < v; j++) {
            if (i == j) {
                floyd[i][j] = 0 ;
            } else {
                floyd[i][j] = inf ;
            }
        }
    }
    for (size_t i = 0; i < e; i++) {
        int a , b , w ; cin >> a >> b >> w ;
        floyd[a][b] = w ;
    }
    for (size_t k = 0; k < v; k++) {
        for (size_t i = 0; i < v; i++) {
            for (size_t j = 0; j < v; j++) {
                if (floyd[i][k] != inf && floyd[k][j] != inf && floyd[i][j] > floyd[i][k] + floyd[k][j]){
                    floyd[i][j] = floyd[i][k] + floyd[k][j] ;
                }
            }
        }
    }
    bool f_neg_cyc = false ;
    for (size_t i = 0; i < v; i++) {
        if (floyd[i][i] < 0){
            f_neg_cyc = true ;
            break;
        }
    }
    if (f_neg_cyc) {
        cout << -1 ;
    } else {
        for (size_t i = 0; i < v; i++) {
            cout << floyd[s][i] << " " ;
        }
    }
 }