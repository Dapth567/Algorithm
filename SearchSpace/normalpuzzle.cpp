#include <bits/stdc++.h>

using namespace std  ;
map<int,string> decrypt1 = {{0,"U"},{1,"D"}, {2,"L"}, {3,"R"}} ;
map<int,string> decrypt2 = {{0,"1"},{1,"2"}, {2,"3"}, {3,"4"}} ;
set<vector<vector<int>>> found_board ;
int cal_heu(vector<vector<int>>& board){
    int n  =  board.size() ;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != (i*n) + (j+1)){
                count += min(abs((board[i][j]/4) - i), n/2 );
                count += min(abs((board[i][j]%4) - j), n/2 );
            }
        }
    }
    return count ;
}
void change(vector<vector<int>>& b , int moves , int rc ){
    vector<int> n ;
    if (moves == 0){
        for (size_t i = 0; i < b.size(); i++) {
            n.push_back(b[i][rc]);
        }
        b[b.size()-1][rc] = n[0];
        for (size_t i = 0; i < b.size()-1; i++)
        {
            b[i][rc] = n[i+1] ;
        }
    } else if (moves == 1){ // d
        for (size_t i = 0; i < b.size(); i++) {
            n.push_back(b[i][rc]);
        }
        b[0][rc] = n[b.size()-1];
        for (size_t i = 0; i < b.size()-1; i++)
        {
            b[i+1][rc] = n[i] ;
        }        
    } else if (moves == 2){ // l
        for (size_t i = 0; i < b.size(); i++) {
            n.push_back(b[rc][i]);
        }
        b[rc][b.size()-1] = n[0];
        for (size_t i = 0; i < b.size()-1; i++)
        {
            b[rc][i] = n[i+1];
        }          
    } else if (moves == 3){ // r
        for (size_t i = 0; i < b.size(); i++) {
            n.push_back(b[rc][i]);
        }
        b[rc][0] = n[b.size()-1];
        for (size_t i = 0; i < b.size()-1; i++)
        {
            b[rc][i+1] = n[i];
        }          
    }
}
 
int main(){
    int n ; cin >> n ;
    vector<vector<int>> board(n,vector<int>(n));
    vector<string> sol ;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    priority_queue< tuple<int,vector<string>,vector<vector<int>>>, vector<tuple<int,vector<string>,vector<vector<int>>>> , greater<tuple<int,vector<string>,vector<vector<int>>>>> pq ;
    pq.push({cal_heu(board),sol,board});
    while (!pq.empty()) {
        auto [x,s,b] = pq.top() ; pq.pop() ;
        if (found_board.find(b) != found_board.end()){
            continue;
        } else {
            found_board.insert(b);
        }
        for (size_t i = 0; i < 4; i++) { // u d l r 
            for (size_t j = 0; j < n; j++) {
                string move ;
                vector<vector<int>> cb(b);
                vector<string> cs(s) ;
                change(cb,i,j);
                move = decrypt2[j] + decrypt1[i];
                cs.push_back(move);
                if (cal_heu(cb) == 0){
                    cout << cs.size() << "\n";
                    for (auto m : cs) {
                        cout << m << "\n";
                    }
                    return 0 ;
                } else {
                    pq.push({cal_heu(cb)+cs.size(),cs,cb});
                }
            }   
        }   
    }
}