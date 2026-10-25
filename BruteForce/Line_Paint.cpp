#include <bits/stdc++.h>

using namespace std ;

map<int,int> begin_end ;

void try_merge(int& start, int& stop){

    if (begin_end.size() == 1){
        return ;
    }

    auto it_bef = begin_end.find(start) ;
    if (it_bef += begin_end.begin()){
        --it_bef;
        int prev_start = it_bef->first , prev_stop = it_bef->second ;
        if ((prev_stop) + 1 >= start){
            if (prev_stop >= stop){
                begin_end.erase(start);
                return ;
            } else {
                begin_end[prev_start] = stop ;
                begin_end.erase(start) ;
                start = prev_start ;
                stop = begin_end[prev_start] ;
                try_merge(start,stop) ;
            }
        }
    }

    auto it_next = begin_end.find(start) ;
    ++it_next;
    if (it_next != begin_end.end()){
        int next_start = it_next->first , next_stop = it_next->second ;
        if (stop + 1 >= next_start){
            if (stop > next_stop){
                begin_end.erase(next_start);
                try_merge(start,stop);
            } else  {
                begin_end[start] = next_stop ;
                stop = next_stop ;
                begin_end.erase(next_start) ;
                try_merge(start,stop) ;
            }
        }
    }
}

int main(){
    int n , start, stop ;
    cin >> n ;
    while (n--) {
        cin >> start >> stop ;
        if (begin_end.find(start) == begin_end.end()) {
            begin_end[start] = stop ;
        } else {
            if (stop > begin_end[start] ) {
                begin_end[start] = stop ;
            }
        }
        try_merge(start,stop) ;
    }
    for (auto it = begin_end.begin() ; it != begin_end.end() ; it++) {
        cout << it->first << " " << it->second << " " ;
    }
}