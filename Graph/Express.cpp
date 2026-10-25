#include <bits/stdc++.h>

using namespace std ;

const int inf = 1e9 ;

int main() {
    int n  ; cin >> n ;
    int floyd[n][n] ;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if ( i != j ) {
                floyd[i][j] = inf ;
            } else {
                floyd[i][j] = 0 ;
            }
        }
    }
    int value ; cin >> value ;
    floyd[0][1] = value ;
    floyd[1][0] = value ;
    for (size_t i = 2; i < n; i++) {
        int am ; cin >> am ;
        while (am--) {
            int node , weight ; cin >> node >> weight ;
            node--;
            floyd[node][i] = weight ;
            floyd[i][node] = weight ;
        }
    }
    for (size_t k = 0; k < n; k++) {
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                if (floyd[i][k] != inf && floyd[k][j] != inf && floyd[i][j] > floyd[i][k] + floyd[k][j]){
                    floyd[i][j] = floyd[i][k] + floyd[k][j] ;
                }
            }
            
        }
        if (k > 1){
            cout << floyd[0][1] << " " ;
        }
    }
}