#include <bits/stdc++.h>
using namespace std ;
const int inf = 1e9 ;
int main() {
    int max_ans  = 0;
    int n, e ; cin >> n >> e ;
    int floyd[n][n] ;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i != j){
                floyd[i][j] = inf ;
            } else {
                floyd[i][j] = 0 ;
            }
        }
    }
    for (size_t i = 0; i < e; i++) {
        int a , b , w ; cin >> a >> b >> w ;
        floyd[a][b] = w ;
        floyd[b][a] = w ;
    }
    for (size_t k = 0; k < n; k++) {
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                if (floyd[i][k] != inf && floyd[k][j] != inf && floyd[i][j] > floyd[i][k] + floyd[k][j]) {
                    floyd[i][j] = floyd[i][k] + floyd[k][j] ;
                }
            }
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i != j && floyd[i][j] != inf)
            max_ans = max(max_ans,floyd[i][j]);
        }
    }
    cout << max_ans ;
}