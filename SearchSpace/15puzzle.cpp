#include <bits/stdc++.h>

using namespace std ;
int dx[4] = {0,0,1,-1} , dy[4] = {1,-1,0,0} ;
map<int,int> opposite = {{0,1},{1,0},{2,3},{3,2},{-1,-1}};
map<int,string>  encrypt = {{0,"R"},{1,"L"},{2,"U"},{3,"D"}} ;
  
int cal_heu(vector<vector<int>>& board,int step){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0){
                continue;
            } else if (board[i][j] == (i*4) + (j+1)){
                continue;
            } else {
                int grid_val = board[i][j] - 1 ;
                int x_val = grid_val/4 , y_val = grid_val%4 ;
                step += abs(x_val-i);
                step += abs(y_val-j); 
            }
        }
    }
    return step ;
}

int main(){
    set<vector<vector<int>>> found_board ;
    vector<vector<int>> arr(4,vector<int>(4)) ;
    int wrong_count = 0 ;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j] ;
        }
    }
    priority_queue < tuple<int,vector<vector<int>>,int,string> ,vector<tuple<int,vector<vector<int>>,int,string>>, greater<tuple<int,vector<vector<int>>,int,string>>> pq ;
    
    pq.push({cal_heu(arr,0),arr,-1,""});
    while (!pq.empty()) {
        bool swapped = false ;
        auto [huristic,board,last_move,moveorder] = pq.top() ; pq.pop() ;
        int moves = moveorder.size() ;
        found_board.insert(board) ;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if ( !board[i][j] ) {
                    for (int k = 0; k < 4; k++) {
                        int x = dx[k] , y = dy[k] ;
                        if (opposite[last_move] != k && i + x >= 0 && i + x <= 3 && j + y >= 0 && j + y <= 3) {
                            vector<vector<int>> cop_board(board) ;
                            swap(cop_board[i][j],cop_board[i+x][j+y]) ;
                            if (found_board.find(cop_board) != found_board.end()) continue;
                            int heu = cal_heu(cop_board,moves+1) ;
                            if (heu == moves+1) {
                                cout << heu << endl << moveorder;
                                return 0 ;
                            }
                            pq.push({heu,cop_board,k,moveorder+encrypt[k]});
                        }
                    }
                    swapped = true ;
                }
                if(swapped) break ;
            }
            if(swapped) break; 
        }
    }
}

#include <bits/stdc++.h>

using namespace std ;
int dx[4] = {0,0,1,-1} , dy[4] = {1,-1,0,0} ;
map<int,int> opposite = {{0,1},{1,0},{2,3},{3,2},{-1,-1}};

int cal_heu(vector<vector<int>>& board,int step){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0){
                continue;
            } else if (board[i][j] == (i*4) + (j+1)){
                continue;
            } else {
                int grid_val = board[i][j] - 1 ;
                int x_val = grid_val/4 ;
                int y_val = grid_val%4 ;
                step += abs(x_val-i);
                step += abs(y_val-j); 
            }
        }
    }
    return step ;
}

int main(){
    set<vector<vector<int>>> found_board ;
    vector<vector<int>> arr(4,vector<int>(4)) ;
    int wrong_count = 0 ;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j] ;
            if (arr[i][j] != (i*4) + (j + 1) && arr[i][j] != 0) {
                wrong_count++;
            }
        }
    }
    priority_queue < tuple<int,int,vector<vector<int>>,int> ,vector<tuple<int,int,vector<vector<int>>,int>>, greater<tuple<int,int,vector<vector<int>>,int>>> pq ;
    pq.push({wrong_count,0,arr,-1});
    bool found = false ;
    while (!pq.empty()) {
        bool swapped = false ;
        auto [huristic,moves,board,last_move] = pq.top() ; pq.pop() ;
        found_board.insert(board) ;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if ( board[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int x = dx[k] , y = dy[k] ;
                        if (opposite[last_move] != k && i + x >= 0 && i + x <= 3 && j + y >= 0 && j + y <= 3) {
                            vector<vector<int>> cop_board(board) ;
                            swap(cop_board[i][j],cop_board[i+x][j+y]) ;
                            if (found_board.find(cop_board) != found_board.end()) {
                                continue;
                            } 
                            int heu = cal_heu(cop_board,moves+1) ;
                            if (heu == moves+1) {
                                cout << heu ;
                                found = true ;
                                break;
                            }
                            pq.push({heu,moves+1,cop_board,k});
                        }
                    }
                    swapped = true ;
                }
                if(swapped) break ;
            }
            if(swapped) break; 
        }
        if (found) break; 
    }
    
}


// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// int dx[4] = {-1, 1, 0, 0}; // U, D, L, R
// int dy[4] = {0, 0, -1, 1};
// char move_chars[4] = {'D', 'U', 'R', 'L'};

// // ฟังก์ชันคำนวณ Manhattan Distance + Linear Conflict
// int get_heuristic(const vector<int>& board) {
//     int h = 0;
//     int conf = 0;

//     // Manhattan Distance
//     for (int i = 0; i < 16; i++) {
//         if (board[i] == 0) continue;
//         int target_x = (board[i] - 1) / 4;
//         int target_y = (board[i] - 1) % 4;
//         int cur_x = i / 4;
//         int cur_y = i % 4;
//         h += abs(cur_x - target_x) + abs(cur_y - target_y);
//     }

//     // Row Linear Conflict
//     for (int r = 0; r < 4; r++) {
//         for (int i = 0; i < 4; i++) {
//             for (int j = i + 1; j < 4; j++) {
//                 int val_i = board[r * 4 + i];
//                 int val_j = board[r * 4 + j];
//                 if (val_i != 0 && val_j != 0) {
//                     if ((val_i - 1) / 4 == r && (val_j - 1) / 4 == r) {
//                         if (val_i > val_j) conf += 2;
//                     }
//                 }
//             }
//         }
//     }

//     // Column Linear Conflict
//     for (int c = 0; c < 4; c++) {
//         for (int i = 0; i < 4; i++) {
//             for (int j = i + 1; j < 4; j++) {
//                 int val_i = board[i * 4 + c];
//                 int val_j = board[j * 4 + c];
//                 if (val_i != 0 && val_j != 0) {
//                     if ((val_i - 1) % 4 == c && (val_j - 1) % 4 == c) {
//                         if (val_i > val_j) conf += 2;
//                     }
//                 }
//             }
//         }
//     }
//     return h + conf;
// }

// string path = "";
// bool solved = false;
// int next_threshold;

// void dfs(vector<int>& board, int g, int h, int prev_move, int limit) {
//     if (g + h > limit) {
//         next_threshold = min(next_threshold, g + h);
//         return;
//     }
//     if (h == 0) {
//         solved = true;
//         return;
//     }

//     int zero_pos;
//     for (int i = 0; i < 16; i++) if (board[i] == 0) { zero_pos = i; break; }

//     int z_r = zero_pos / 4;
//     int z_c = zero_pos % 4;

//     for (int i = 0; i < 4; i++) {
//         // ห้ามเดินย้อนกลับที่เดิม
//         if (prev_move != -1 && (prev_move ^ 1) == i) continue;

//         int nr = z_r + dx[i];
//         int nc = z_c + dy[i];

//         if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4) {
//             int next_pos = nr * 4 + nc;
            
//             // สลับที่
//             swap(board[zero_pos], board[next_pos]);
            
//             int new_h = get_heuristic(board);
//             path.push_back(move_chars[i]);
            
//             dfs(board, g + 1, new_h, i, limit);
            
//             if (solved) return;
            
//             // backtrack
//             path.pop_back();
//             swap(board[zero_pos], board[next_pos]);
//         }
//     }
// }

// int main() {
//     vector<int> board(16);
//     for (int i = 0; i < 16; i++) cin >> board[i];

//     int h = get_heuristic(board);
//     int limit = h;

//     cout << "Solving..." << endl;
    
//     while (!solved && limit <= 80) { // จำกัดไว้ที่ 80 ก้าวเผื่อกรณีหาไม่เจอ
//         next_threshold = INT_MAX;
//         dfs(board, 0, h, -1, limit);
//         if (!solved) limit = next_threshold;
//     }

//     if (solved) {
//         cout << "Steps: " << path.length() << endl;
//         cout << "Path: " << path << endl;
//     } else {
//         cout << "No solution found within limit." << endl;
//     }

//     return 0;
// }