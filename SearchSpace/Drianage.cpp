#include <bits/stdc++.h>

using namespace std ;

int main(){
    int count = 0 ;
    int l , n ; 
    cin >> n >> l;
    vector<int> hole(n);
    for (size_t i = 0; i < n; i++) { cin >> hole[i] ; }
    sort(hole.begin(),hole.end()) ;
    for (size_t i = 0; i < n; i++) {
        count++ ;
        int s_pos = hole[i];
        while (i+1 < n) {
            if (s_pos + l - 1 >= hole[i+1]) {
                i++ ;
            } else {
                break;
            }
        }
    }
    cout << count ;
}