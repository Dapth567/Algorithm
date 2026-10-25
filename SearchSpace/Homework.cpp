
#include <bits/stdc++.h>   //ใช้คิดข้อ 1
using namespace std;

int N;
int target[65][65];

const int DR[] = { 1, -1,  0,  0};
const int DC[] = { 0,  0,  1, -1};
const char MV[] = {'U','D','L','R'};
const int OPP[] = { 1,  0,  3,  2};

using Board = vector<int>;

int heuristic(const Board& b) {
    int wrong = 0;
    for (int r = 0; r < N-2; r++)
        for (int c = 0; c < N-2; c++)
            if (b[(r+1)*N+(c+1)] != target[r][c])
                wrong++;
    return wrong;
}

string result;
bool found;

int dfs(Board& b, int br, int bc, int g, int bound, int lastDir, string& path) {
    int h = heuristic(b);
    int f = g + h;
    if (f > bound) return f;
    if (h == 0) {
        found = true;
        result = path;
        return 0;
    }

    int minExceeded = INT_MAX;
    for (int d = 0; d < 4; d++) {
        if (lastDir != -1 && d == OPP[lastDir]) continue;

        int nr = br + DR[d];
        int nc = bc + DC[d];
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

        swap(b[br*N+bc], b[nr*N+nc]);
        path.push_back(MV[d]);

        int t = dfs(b, nr, nc, g+1, bound, d, path);
        if (found) return 0;
        if (t < minExceeded) minExceeded = t;

        path.pop_back();
        swap(b[br*N+bc], b[nr*N+nc]);
    }
    return minExceeded;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    Board board(N*N);
    int startR = 0, startC = 0;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            cin >> board[r*N+c];
            if (board[r*N+c] == -1) { startR = r; startC = c; }
        }

    for (int r = 0; r < N-2; r++)
        for (int c = 0; c < N-2; c++)
            cin >> target[r][c];

    if (heuristic(board) == 0) { cout << "S\n"; return 0; }

    int bound = heuristic(board);
    string path;
    found = false;

    while (!found) {
        int t = dfs(board, startR, startC, 0, bound, -1, path);
        if (found) break;
        if (t == INT_MAX) { cout << "S\n"; return 0; }
        bound = t;
    }

    cout << result << "S\n";
    return 0;
}

// #include <iostream> // ข้อ 2 3
// #include <vector>
// #include <string>
// #include <queue>
// #include <cmath>
// #include <algorithm>

// using namespace std;

// int N;
// vector<vector<int>> board;
// vector<vector<int>> target;
// vector<vector<bool>> locked;
// int blank_r = -1, blank_c = -1;
// string moves_str = "";

// // ฟังก์ชันขยับช่องว่าง พร้อมระบบป้องกันขอบเขต (Bounds Checking) ป้องกันตัวแตก
// void apply_move(char m) {
//     int dr = 0, dc = 0;
//     if (m == 'U') { dr = 1; dc = 0; }
//     else if (m == 'D') { dr = -1; dc = 0; }
//     else if (m == 'L') { dr = 0; dc = 1; }
//     else if (m == 'R') { dr = 0; dc = -1; }
    
//     int nr = blank_r + dr;
//     int nc = blank_c + dc;
    
//     if (nr < 0 || nr >= N || nc < 0 || nc >= N) return; // กันพังกรณีบัคหลุด
    
//     swap(board[blank_r][blank_c], board[nr][nc]);
//     blank_r = nr;
//     blank_c = nc;
//     moves_str += m;
// }

// // ฟังก์ชันหา "ก้าวต่อไป" ของกระเบื้องเป้าหมาย โดยต้องเดินหลบช่องที่ Locked 
// pair<int, int> get_next_tile_pos(int tr, int tc, int br, int bc) {
//     queue<pair<int, int>> q;
//     vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));
//     q.push({tr, tc});
//     parent[tr][tc] = {tr, tc};
    
//     int dr[] = {1, -1, 0, 0};
//     int dc[] = {0, 0, 1, -1};
    
//     while (!q.empty()) {
//         auto curr = q.front();
//         q.pop();
        
//         if (curr.first == br && curr.second == bc) break;
        
//         for (int i = 0; i < 4; ++i) {
//             int nr = curr.first + dr[i];
//             int nc = curr.second + dc[i];
            
//             if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
//                 if (parent[nr][nc].first == -1 && !locked[nr][nc]) {
//                     parent[nr][nc] = curr;
//                     q.push({nr, nc});
//                 }
//             }
//         }
//     }
    
//     if (parent[br][bc].first == -1) return {-1, -1}; // ไม่มีทางเดิน
    
//     int curr_r = br, curr_c = bc;
//     while (parent[curr_r][curr_c].first != tr || parent[curr_r][curr_c].second != tc) {
//         auto p = parent[curr_r][curr_c];
//         curr_r = p.first;
//         curr_c = p.second;
//     }
//     return {curr_r, curr_c};
// }

// // ฟังก์ชันเดินช่องว่าง (-1) ไปยังตำแหน่งที่ต้องการ (แก้ปัญหากิน Mem โดยใช้ Parent array)
// string bfs_blank_to(int goal_r, int goal_c, int avoid_r, int avoid_c) {
//     if (blank_r == goal_r && blank_c == goal_c) return "";
    
//     queue<pair<int, int>> q;
//     vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));
//     vector<vector<char>> move_char(N, vector<char>(N, ' '));
    
//     q.push({blank_r, blank_c});
//     parent[blank_r][blank_c] = {blank_r, blank_c};
    
//     int dr[] = {1, -1, 0, 0};
//     int dc[] = {0, 0, 1, -1};
//     char m_chars[] = {'U', 'D', 'L', 'R'}; 
    
//     while (!q.empty()) {
//         auto curr = q.front();
//         q.pop();
        
//         if (curr.first == goal_r && curr.second == goal_c) break;
        
//         for (int i = 0; i < 4; ++i) {
//             int nr = curr.first + dr[i];
//             int nc = curr.second + dc[i];
            
//             if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
//                 if (parent[nr][nc].first == -1 && !locked[nr][nc] && (nr != avoid_r || nc != avoid_c)) {
//                     parent[nr][nc] = curr;
//                     move_char[nr][nc] = m_chars[i];
//                     q.push({nr, nc});
//                 }
//             }
//         }
//     }
    
//     if (parent[goal_r][goal_c].first == -1) return "FAIL"; // หาทางไม่เจอ
    
//     string path = "";
//     int curr_r = goal_r, curr_c = goal_c;
//     while (curr_r != blank_r || curr_c != blank_c) {
//         path += move_char[curr_r][curr_c];
//         auto p = parent[curr_r][curr_c];
//         curr_r = p.first;
//         curr_c = p.second;
//     }
//     reverse(path.begin(), path.end());
//     return path;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     if (!(cin >> N)) return 0;

//     board.resize(N, vector<int>(N));
//     locked.resize(N, vector<bool>(N, false));
//     target.resize(N - 2, vector<int>(N - 2));
    
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < N; ++j) {
//             cin >> board[i][j];
//             if (board[i][j] == -1) {
//                 blank_r = i;
//                 blank_c = j;
//             }
//         }
//     }

//     for (int i = 0; i < N - 2; ++i) {
//         for (int j = 0; j < N - 2; ++j) {
//             cin >> target[i][j];
//         }
//     }

//     // แก้ทีละช่องของ Target
//     for (int i = 0; i < N - 2; ++i) {
//         for (int j = 0; j < N - 2; ++j) {
//             int target_val = target[i][j];
//             int board_r = i + 1;
//             int board_c = j + 1;

//             if (board[board_r][board_c] == target_val) {
//                 locked[board_r][board_c] = true;
//                 continue;
//             }

//             // หา Candidates กระเบื้องสีที่ต้องการทั้งหมด
//             vector<pair<int, int>> candidates;
//             for (int r = 0; r < N; ++r) {
//                 for (int c = 0; c < N; ++c) {
//                     if (board[r][c] == target_val && !locked[r][c]) {
//                         candidates.push_back({r, c});
//                     }
//                 }
//             }
            
//             // เรียงลำดับเอาชิ้นที่อยู่ใกล้เป้าหมายที่สุดขึ้นก่อน
//             sort(candidates.begin(), candidates.end(), [&](pair<int, int>& a, pair<int, int>& b) {
//                 return abs(a.first - board_r) + abs(a.second - board_c) < 
//                        abs(b.first - board_r) + abs(b.second - board_c);
//             });

//             bool placed = false;
//             // ลองลากกระเบื้องทีละตัว ถ้าตัวใกล้สุดโดนปิดตาย ให้ลองตัวถัดไป
//             for (auto tile : candidates) {
//                 int tile_r = tile.first;
//                 int tile_c = tile.second;
//                 bool drag_success = true;

//                 while (tile_r != board_r || tile_c != board_c) {
//                     pair<int, int> next_pos = get_next_tile_pos(tile_r, tile_c, board_r, board_c);
//                     if (next_pos.first == -1) {
//                         drag_success = false; break; // กระเบื้องนี้โดนขัง
//                     }
//                     int next_r = next_pos.first;
//                     int next_c = next_pos.second;

//                     string path = bfs_blank_to(next_r, next_c, tile_r, tile_c);
//                     if (path == "FAIL") {
//                         drag_success = false; break; // ช่องว่าง(-1) โดนขัง ไปดึงไม่ได้
//                     }

//                     for (char m : path) apply_move(m);

//                     if (next_r < tile_r) apply_move('U');
//                     else if (next_r > tile_r) apply_move('D');
//                     else if (next_c < tile_c) apply_move('L');
//                     else if (next_c > tile_c) apply_move('R');
                    
//                     tile_r = next_r;
//                     tile_c = next_c;
//                 }

//                 if (drag_success) {
//                     placed = true;
//                     break; // ทำสำเร็จ ไปทำช่อง Target ถัดไป
//                 }
//             }
//             // ถึงจะลากมาไม่สำเร็จ (ซึ่งแทบไม่เกิด) ก็ต้องล็อคไว้เพื่อไม่ให้ติด Infinite Loop 
//             locked[board_r][board_c] = true; 
//         }
//     }
    
//     // กรองคำสั่งซ้ำซ้อนเพื่อปั่นคะแนนเต็ม
//     string optimized_moves = "";
//     for (char c : moves_str) {
//         if (!optimized_moves.empty()) {
//             char last = optimized_moves.back();
//             if ((last == 'U' && c == 'D') || (last == 'D' && c == 'U') ||
//                 (last == 'L' && c == 'R') || (last == 'R' && c == 'L')) {
//                 optimized_moves.pop_back(); 
//                 continue;
//             }
//         }
//         optimized_moves += c;
//     }

//     cout << optimized_moves << "S\n";

//     return 0;
// }

// #include <iostream>   3 4 5 6 ver
// #include <vector>
// #include <string>
// #include <queue>
// #include <cmath>
// #include <algorithm>

// using namespace std;

// int N;
// vector<vector<int>> board;
// vector<vector<int>> target;
// vector<vector<bool>> locked;
// int blank_r = -1, blank_c = -1;
// string moves_str = "";

// // ฟังก์ชันขยับช่องว่าง (-1)
// void apply_move(char m) {
//     int dr = 0, dc = 0;
//     if (m == 'U') { dr = 1; dc = 0; }
//     else if (m == 'D') { dr = -1; dc = 0; }
//     else if (m == 'L') { dr = 0; dc = 1; }
//     else if (m == 'R') { dr = 0; dc = -1; }
    
//     int nr = blank_r + dr;
//     int nc = blank_c + dc;
    
//     if (nr < 0 || nr >= N || nc < 0 || nc >= N) return;
    
//     swap(board[blank_r][blank_c], board[nr][nc]);
//     blank_r = nr;
//     blank_c = nc;
//     moves_str += m;
// }

// // ฟังก์ชันหาเส้นทางลากกระเบื้อง
// pair<int, int> get_next_tile_pos(int tr, int tc, int br, int bc) {
//     queue<pair<int, int>> q;
//     vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));
//     q.push({tr, tc});
//     parent[tr][tc] = {tr, tc};
    
//     int dr[] = {1, -1, 0, 0};
//     int dc[] = {0, 0, 1, -1};
    
//     while (!q.empty()) {
//         auto curr = q.front();
//         q.pop();
        
//         if (curr.first == br && curr.second == bc) break;
        
//         for (int i = 0; i < 4; ++i) {
//             int nr = curr.first + dr[i];
//             int nc = curr.second + dc[i];
            
//             if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
//                 if (parent[nr][nc].first == -1 && !locked[nr][nc]) {
//                     parent[nr][nc] = curr;
//                     q.push({nr, nc});
//                 }
//             }
//         }
//     }
    
//     if (parent[br][bc].first == -1) return {-1, -1}; 
    
//     int curr_r = br, curr_c = bc;
//     while (parent[curr_r][curr_c].first != tr || parent[curr_r][curr_c].second != tc) {
//         auto p = parent[curr_r][curr_c];
//         curr_r = p.first;
//         curr_c = p.second;
//     }
//     return {curr_r, curr_c};
// }

// // ฟังก์ชันเดินช่องว่าง (-1)
// string bfs_blank_to(int goal_r, int goal_c, int avoid_r, int avoid_c) {
//     if (blank_r == goal_r && blank_c == goal_c) return "";
    
//     queue<pair<int, int>> q;
//     vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));
//     vector<vector<char>> move_char(N, vector<char>(N, ' '));
    
//     q.push({blank_r, blank_c});
//     parent[blank_r][blank_c] = {blank_r, blank_c};
    
//     int dr[] = {1, -1, 0, 0};
//     int dc[] = {0, 0, 1, -1};
//     char m_chars[] = {'U', 'D', 'L', 'R'}; 
    
//     while (!q.empty()) {
//         auto curr = q.front();
//         q.pop();
        
//         if (curr.first == goal_r && curr.second == goal_c) break;
        
//         for (int i = 0; i < 4; ++i) {
//             int nr = curr.first + dr[i];
//             int nc = curr.second + dc[i];
            
//             if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
//                 if (parent[nr][nc].first == -1 && !locked[nr][nc] && (nr != avoid_r || nc != avoid_c)) {
//                     parent[nr][nc] = curr;
//                     move_char[nr][nc] = m_chars[i];
//                     q.push({nr, nc});
//                 }
//             }
//         }
//     }
    
//     if (parent[goal_r][goal_c].first == -1) return "FAIL"; 
    
//     string path = "";
//     int curr_r = goal_r, curr_c = goal_c;
//     while (curr_r != blank_r || curr_c != blank_c) {
//         path += move_char[curr_r][curr_c];
//         auto p = parent[curr_r][curr_c];
//         curr_r = p.first;
//         curr_c = p.second;
//     }
//     reverse(path.begin(), path.end());
//     return path;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     if (!(cin >> N)) return 0;

//     board.resize(N, vector<int>(N));
//     locked.resize(N, vector<bool>(N, false));
//     target.resize(N - 2, vector<int>(N - 2));
    
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < N; ++j) {
//             cin >> board[i][j];
//             if (board[i][j] == -1) {
//                 blank_r = i;
//                 blank_c = j;
//             }
//         }
//     }

//     for (int i = 0; i < N - 2; ++i) {
//         for (int j = 0; j < N - 2; ++j) {
//             cin >> target[i][j];
//         }
//     }

//     for (int i = 0; i < N - 2; ++i) {
//         for (int j = 0; j < N - 2; ++j) {
//             int target_val = target[i][j];
//             int board_r = i + 1;
//             int board_c = j + 1;

//             if (board[board_r][board_c] == target_val) {
//                 locked[board_r][board_c] = true;
//                 continue;
//             }

//             vector<pair<int, int>> candidates;
//             for (int r = 0; r < N; ++r) {
//                 for (int c = 0; c < N; ++c) {
//                     if (board[r][c] == target_val && !locked[r][c]) {
//                         candidates.push_back({r, c});
//                     }
//                 }
//             }
            
//             // --- OPTIMIZATION: Smart Tile Selection Heuristic ---
//             sort(candidates.begin(), candidates.end(), [&](pair<int, int>& a, pair<int, int>& b) {
//                 // 1. คำนวณระยะห่างไปเป้าหมาย (ให้น้ำหนัก x5 เพราะการลากกระเบื้อง 1 ก้าวต้องใช้ช่องว่างเดินล้อมรอบหลายก้าว)
//                 int dist_a_target = abs(a.first - board_r) + abs(a.second - board_c);
//                 int dist_b_target = abs(b.first - board_r) + abs(b.second - board_c);
                
//                 // 2. คำนวณระยะที่ช่องว่าง (-1) ต้องเดินไปหากระเบื้องชิ้นนั้น
//                 int dist_a_blank = abs(blank_r - a.first) + abs(blank_c - a.second);
//                 int dist_b_blank = abs(blank_r - b.first) + abs(blank_c - b.second);
                
//                 // 3. Penalty: พยายามอย่าดึงกระเบื้องที่บังเอิญตกอยู่ในโซนตรงกลาง (เว้นแต่จำเป็น) ให้ดึงจากขอบนอกก่อน
//                 int penalty_a = (a.first >= 1 && a.first <= N-2 && a.second >= 1 && a.second <= N-2) ? 8 : 0;
//                 int penalty_b = (b.first >= 1 && b.first <= N-2 && b.second >= 1 && b.second <= N-2) ? 8 : 0;
                
//                 int cost_a = (dist_a_target * 5) + dist_a_blank + penalty_a;
//                 int cost_b = (dist_b_target * 5) + dist_b_blank + penalty_b;
                
//                 return cost_a < cost_b;
//             });

//             bool placed = false;
//             for (auto tile : candidates) {
//                 int tile_r = tile.first;
//                 int tile_c = tile.second;
//                 bool drag_success = true;

//                 while (tile_r != board_r || tile_c != board_c) {
//                     pair<int, int> next_pos = get_next_tile_pos(tile_r, tile_c, board_r, board_c);
//                     if (next_pos.first == -1) { drag_success = false; break; }
                    
//                     int next_r = next_pos.first;
//                     int next_c = next_pos.second;

//                     string path = bfs_blank_to(next_r, next_c, tile_r, tile_c);
//                     if (path == "FAIL") { drag_success = false; break; }

//                     for (char m : path) apply_move(m);

//                     if (next_r < tile_r) apply_move('U');
//                     else if (next_r > tile_r) apply_move('D');
//                     else if (next_c < tile_c) apply_move('L');
//                     else if (next_c > tile_c) apply_move('R');
                    
//                     tile_r = next_r;
//                     tile_c = next_c;
//                 }

//                 if (drag_success) {
//                     placed = true;
//                     break;
//                 }
//             }
//             locked[board_r][board_c] = true; 
//         }
//     }
    
//     // --- OPTIMIZATION: Advanced Move Cancellation ---
//     // กรองคำสั่งเดินวนซ้ำลูกโซ่ (เช่น U L R D ซ้ายขวาตัดกันเหลือ U D แล้วก็ตัดกันเองอีกทอด)
//     string optimized_moves = "";
//     for (char c : moves_str) {
//         if (!optimized_moves.empty()) {
//             char last = optimized_moves.back();
//             if ((last == 'U' && c == 'D') || (last == 'D' && c == 'U') ||
//                 (last == 'L' && c == 'R') || (last == 'R' && c == 'L')) {
//                 optimized_moves.pop_back(); 
//                 continue;
//             }
//         }
//         optimized_moves += c;
//     }

//     cout << optimized_moves << "S\n";

//     return 0;
// }

// #include <iostream>   //  better casse 4
// #include <vector>
// #include <string>
// #include <queue>
// #include <cmath>
// #include <algorithm>

// using namespace std;

// int N;
// vector<vector<int>> board;
// vector<vector<int>> target;
// vector<vector<bool>> locked;
// int blank_r = -1, blank_c = -1;
// string moves_str = "";

// // ฟังก์ชันสลับตำแหน่งช่องว่าง (-1)
// void apply_move(char m) {
//     int dr = 0, dc = 0;
//     if (m == 'U') { dr = 1; dc = 0; }
//     else if (m == 'D') { dr = -1; dc = 0; }
//     else if (m == 'L') { dr = 0; dc = 1; }
//     else if (m == 'R') { dr = 0; dc = -1; }
    
//     int nr = blank_r + dr;
//     int nc = blank_c + dc;
    
//     if (nr < 0 || nr >= N || nc < 0 || nc >= N) return;
    
//     swap(board[blank_r][blank_c], board[nr][nc]);
//     blank_r = nr;
//     blank_c = nc;
//     moves_str += m;
// }

// // ฟังก์ชันหาทางให้ช่องว่าง (-1) ไปรอที่ตำแหน่งที่กำหนด
// string bfs_blank_to(int goal_r, int goal_c, int avoid_r, int avoid_c) {
//     if (blank_r == goal_r && blank_c == goal_c) return "";
    
//     queue<pair<int, int>> q;
//     vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));
//     vector<vector<char>> move_char(N, vector<char>(N, ' '));
    
//     q.push({blank_r, blank_c});
//     parent[blank_r][blank_c] = {blank_r, blank_c};
    
//     int dr[] = {1, -1, 0, 0};
//     int dc[] = {0, 0, 1, -1};
//     char m_chars[] = {'U', 'D', 'L', 'R'}; 
    
//     while (!q.empty()) {
//         auto curr = q.front();
//         q.pop();
        
//         if (curr.first == goal_r && curr.second == goal_c) break;
        
//         for (int i = 0; i < 4; ++i) {
//             int nr = curr.first + dr[i];
//             int nc = curr.second + dc[i];
            
//             if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
//                 if (parent[nr][nc].first == -1 && !locked[nr][nc] && (nr != avoid_r || nc != avoid_c)) {
//                     parent[nr][nc] = curr;
//                     move_char[nr][nc] = m_chars[i];
//                     q.push({nr, nc});
//                 }
//             }
//         }
//     }
    
//     if (parent[goal_r][goal_c].first == -1) return "FAIL"; 
    
//     string path = "";
//     int curr_r = goal_r, curr_c = goal_c;
//     while (curr_r != blank_r || curr_c != blank_c) {
//         path += move_char[curr_r][curr_c];
//         auto p = parent[curr_r][curr_c];
//         curr_r = p.first;
//         curr_c = p.second;
//     }
//     reverse(path.begin(), path.end());
//     return path;
// }

// // โครงสร้างช่วยเก็บข้อมูลกระเบื้องที่เป็น Candidate
// struct Candidate {
//     int r, c, cost;
//     bool operator<(const Candidate& o) const { return cost < o.cost; }
// };

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     if (!(cin >> N)) return 0;

//     board.resize(N, vector<int>(N));
//     locked.resize(N, vector<bool>(N, false));
//     target.resize(N - 2, vector<int>(N - 2));
    
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < N; ++j) {
//             cin >> board[i][j];
//             if (board[i][j] == -1) {
//                 blank_r = i;
//                 blank_c = j;
//             }
//         }
//     }

//     for (int i = 0; i < N - 2; ++i) {
//         for (int j = 0; j < N - 2; ++j) {
//             cin >> target[i][j];
//         }
//     }

//     // --- OPTIMIZATION: Snake Filling Order (แก้ปัญหาเรียงแบบงูเลื้อย) ---
//     for (int i = 0; i < N - 2; ++i) {
//         int board_r = i + 1;
//         for (int step = 0; step < N - 2; ++step) {
//             // สลับทิศทางซ้ายขวาตามบรรทัด (คู่: ซ้ายไปขวา, คี่: ขวาไปซ้าย)
//             int target_col = (i % 2 == 0) ? step : (N - 3 - step);
//             int board_c = target_col + 1;
//             int target_val = target[i][target_col];

//             if (board[board_r][board_c] == target_val) {
//                 locked[board_r][board_c] = true;
//                 continue;
//             }

//             // --- OPTIMIZATION: Highway Dijkstra (หาเส้นทางด่วนให้กระเบื้อง) ---
//             // รัน Dijkstra จากเป้าหมายแผ่ออกไป เพื่อหาว่ามีกระเบื้องเป้าหมายอยู่ตรงไหนบ้าง 
//             // โดยให้ความสำคัญกับ "ขอบนอก" (Outer Ring) ให้ค่า Cost ต่ำกว่าเพื่อให้มันวิ่งหลบรถติด
//             vector<vector<int>> dist(N, vector<int>(N, 1e9));
//             vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));
//             priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
            
//             pq.push({0, {board_r, board_c}});
//             dist[board_r][board_c] = 0;
            
//             int dr[] = {1, -1, 0, 0};
//             int dc[] = {0, 0, 1, -1};
            
//             while (!pq.empty()) {
//                 auto curr = pq.top();
//                 pq.pop();
//                 int d = curr.first;
//                 int r = curr.second.first;
//                 int c = curr.second.second;
                
//                 if (d > dist[r][c]) continue;
                
//                 for (int k = 0; k < 4; ++k) {
//                     int nr = r + dr[k];
//                     int nc = c + dc[k];
//                     if (nr >= 0 && nr < N && nc >= 0 && nc < N && !locked[nr][nc]) {
//                         // ค่าผ่านทาง: ขอบนอกวิ่งฉิว (cost=2), ตรงกลางรถติด (cost=6)
//                         int weight = (nr == 0 || nr == N - 1 || nc == 0 || nc == N - 1) ? 2 : 6;
                        
//                         if (dist[r][c] + weight < dist[nr][nc]) {
//                             dist[nr][nc] = dist[r][c] + weight;
//                             parent[nr][nc] = {r, c}; // ชี้กลับไปทางเป้าหมาย
//                             pq.push({dist[nr][nc], {nr, nc}});
//                         }
//                     }
//                 }
//             }

//             // รวบรวมกระเบื้องที่เป็น Candidate ทั้งหมด
//             vector<Candidate> candidates;
//             for (int r = 0; r < N; ++r) {
//                 for (int c = 0; c < N; ++c) {
//                     if (board[r][c] == target_val && !locked[r][c] && dist[r][c] < 1e9) {
//                         // คำนวณ Cost รวม: ระยะลากตามเส้นทางด่วน + ระยะที่ช่องว่างต้องเดินไปรับ
//                         int blank_dist = abs(blank_r - r) + abs(blank_c - c);
//                         int total_cost = dist[r][c] * 5 + blank_dist;
//                         candidates.push_back({r, c, total_cost});
//                     }
//                 }
//             }
//             sort(candidates.begin(), candidates.end());

//             // ลากกระเบื้องที่ดีที่สุดกลับมา
//             for (auto cand : candidates) {
//                 int tile_r = cand.r;
//                 int tile_c = cand.c;
//                 bool drag_success = true;

//                 while (tile_r != board_r || tile_c != board_c) {
//                     // ก้าวต่อไปจะวิ่งตาม Parent Pointers ที่ Dijkstra ทำแผนที่ไว้ให้แล้ว
//                     int next_r = parent[tile_r][tile_c].first;
//                     int next_c = parent[tile_r][tile_c].second;

//                     string path = bfs_blank_to(next_r, next_c, tile_r, tile_c);
//                     if (path == "FAIL") { drag_success = false; break; }

//                     for (char m : path) apply_move(m);

//                     if (next_r < tile_r) apply_move('U');
//                     else if (next_r > tile_r) apply_move('D');
//                     else if (next_c < tile_c) apply_move('L');
//                     else if (next_c > tile_c) apply_move('R');
                    
//                     tile_r = next_r;
//                     tile_c = next_c;
//                 }

//                 if (drag_success) break;
//             }
//             locked[board_r][board_c] = true;
//         }
//     }
    
//     // --- OPTIMIZATION: Cascading Move Cancellation (ลบการเดินวนลูปแบบลูกโซ่) ---
//     bool changed = true;
//     while (changed) {
//         changed = false;
//         string optimized_moves = "";
//         for (char c : moves_str) {
//             if (!optimized_moves.empty()) {
//                 char last = optimized_moves.back();
//                 if ((last == 'U' && c == 'D') || (last == 'D' && c == 'U') ||
//                     (last == 'L' && c == 'R') || (last == 'R' && c == 'L')) {
//                     optimized_moves.pop_back(); 
//                     changed = true; // ถ้ามีการหักล้าง ให้รันเช็คซ้ำอีกรอบเผื่อมีหักล้างต่อได้อีก
//                     continue;
//                 }
//             }
//             optimized_moves += c;
//         }
//         moves_str = optimized_moves;
//     }

//     cout << moves_str << "S\n";

//     return 0;
// }