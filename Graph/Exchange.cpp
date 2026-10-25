#include <bits/stdc++.h>
using namespace std ;
int main(){
    int n ; cin >> n ;
    while (n--) {
        int m ; cin >> m ;
        float floyd[m][m] = {0} ;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < m; j++) {
                cin >> floyd[i][j] ;
            }
        }
        for (size_t k = 0; k < m ; k++) {
            for (size_t i = 0; i < m; i++) {
               for (size_t j = 0; j < m; j++) {
                    if (floyd[i][j] < floyd[i][k] * floyd[k][j]){
                        floyd[i][j] = floyd[i][k] * floyd[k][j] ;
                    }
               }
            }
        }
        bool found = false ;
        for (size_t i = 0; i < m; i++) {
            if (floyd[i][i] > 1) {
                found = true ; break ;
            }
        }
        if (found) {
            cout << "YES\n" ;
        } else {
            cout << "NO\n" ;
        }
    }
}