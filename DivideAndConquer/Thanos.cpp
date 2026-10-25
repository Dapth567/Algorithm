#include <bits/stdc++.h>

using namespace std ;

int main() {
    int p , k , A , B ,pos,tow_size;
    cin >> p , k , A , B ;
    tow_size = pow(2,p) ;
    map<int,int> avenger_block ;
    for (size_t i = 0; i < k; i++){   
        cin >> pos ;
        if (avenger_block.find(pos) == avenger_block.end()){
            avenger_block[pos] = 1 ;
        } else {
            avenger_block[pos]++;
        }
    }
}