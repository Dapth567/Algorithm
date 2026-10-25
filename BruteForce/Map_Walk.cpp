#include <bits/stdc++.h>

using namespace std ;

vector<vector<int>> game_map;
int r , c ;

bool out_of_bound(int start_r , int start_c){
    if (start_r > r - 1 || start_c > c-1 || start_r < 0 || start_c < 0){
        return true ;
    } 
    return false ;
}

void map_recur(int start_r, int start_c,string moves, char last_move){

    if (start_r == r - 1 && start_c == c - 1){
        cout << moves << endl;
        return ;
    }

    if (out_of_bound(start_r,start_c)) {
        return ;
    }

    if (game_map[start_r][start_c] == 1) {
        return ;
    } else {
        map_recur(start_r, start_c + 1 , moves + "A" , 'a');
        if (last_move != 'b'){
            map_recur(start_r - 1, start_c , moves + "C" , 'c');
        }
        if (last_move != 'c'){
            map_recur(start_r + 1, start_c , moves + "B" , 'b');
        }
    }

}

int main(){
    int block;
    string moves = "";
    char last_move = 'x';
    cin >> r >> c ;
    vector<int> each_row ;
    
    for( int i = 0 ; i < r ; i++){
        each_row.clear() ;
        for( int j = 0 ; j < c ; j++){
            cin >> block ;
            each_row.push_back(block);
        }
        game_map.push_back(each_row) ;
    }
    map_recur(0,0,moves,last_move);   
    cout << "DONE" ;
}