// #include <bits/stdc++.h>

// using namespace std  ;

// int dx[8] = {1,-1,0,0,1,1,-1,-1} , dy[8] = {0,0,1,-1,1,-1,1,-1} ; 
// int horse[8][2] = { {2,1} , {1,2} , {2,-1} , {-2,1} , {-1,2} , {1,-2} , {-1,-2} , {-2,-1}} ;
// unordered_set<vector<vector<char>>> used_grid ;

// void change(vector<vector<char>>& v , int x ,int y){
//     v[x][y] = 'x' ;
//     for (size_t i = 0; i < v.size(); i++)
//     {
//         for (size_t j = 0; j < v[0].size(); j++)
//         {
//             for (size_t k = 0; k < 8; k++) {
//                 int sx = x + dx[k] , sy = y + dy[k] ;
//                 while (sx>=0 && sy >= 0 && sx <= v.size()-1 && sy <= v[0].size()-1)
//                 {
//                     if (v[sx][sy] == '.'){
//                         v[sx][sy] = '#' ;
//                     }
//                     sx += dx[k] ;
//                     sy += dy[k] ;
//                 }
//                 sx = x + horse[k][0] , sy = y + horse[k][1] ;
//                 if (sx>=0 && sy >= 0 && sx <= v.size()-1 && sy <= v[0].size()-1) {
//                     if (v[sx][sy] == '.'){
//                         v[sx][sy] = '#' ;
//                     }                    
//                 }
//             }
            
//         }
        
//     }
// }

// int check(vector<vector<char>>& v){
//     int count = 0 ;
//     for (size_t i = 0; i < v.size(); i++) {
//         for (size_t j = 0; j < v[0].size(); j++) {
//             if (v[i][j] == '.'){
//                 return 0 ;
//             } else if (v[i][j] == 'x') {
//                 count++;
//             }
//         }
//     }
//     return count ;
// }

// int cal_heu(vector<vector<char>>& v){
//     int count = 0 ;
//     for (size_t i = 0; i < v.size(); i++) {
//         for (size_t j = 0; j < v[0].size(); j++) {
//             if (v[i][j] == 'x' || v[i][j] == '.'){
//                 count++ ;
//             }
//         }
//     }
//     return count ;
// }

// int main(){
//     int n,m ; cin >> n >> m ;
//     vector<vector<char>> v(n,vector<char> (m)) ;
//     for (size_t i = 0; i < n; i++){
//         for (size_t j = 0; j < m; j++){
//             cin >> v[i][j] ;
//         }
//     }
//     priority_queue<pair<int,vector<vector<char>> >, vector<pair<int,vector<vector<char>> >>, greater<pair<int,vector<vector<char>> >> >pq ;
//     pq.push({cal_heu(v),v}) ;
//     while (!pq.empty())
//     {
//         auto [heu,vv] = pq.top() ; pq.pop() ;
//         for (size_t i = 0; i < n; i++)
//         {
//             for (size_t j = 0; j < m; j++)
//             {
//                 if (vv[i][j] == 'x' || v[i][j] == '#' ) {
//                     continue;
//                 } else {
//                     vector<vector<char>> copv(vv);
//                     change(copv,i,j);
//                     int ans = check(copv);
//                     if (ans){
//                         for (size_t b = 0; b < n; b++)
//                         {
//                             for (size_t a = 0; a < m;a ++)
//                             {
//                                 if (copv[b][a] == 'x'){
//                                     cout << 'X' ;
//                                 } else {
//                                     cout << v[b][a] ;
//                                 }
//                             }
//                             cout << "\n" ;
//                         }
//                         return 0 ;
//                     }
//                     pq.push({cal_heu(copv),copv});
//                 }
//             }   
//         }   
//     }
// }

// #include <bits/stdc++.h>

// using namespace std  ;

// int dx[8] = {1,-1,0,0,1,1,-1,-1} , dy[8] = {0,0,1,-1,1,-1,1,-1} ; 
// int horse[8][2] = { {2,1} , {1,2} , {2,-1} , {-2,1} , {-1,2} , {1,-2} , {-1,-2} , {-2,-1}} ;

// void change(vector<vector<char>>& v , int x ,int y){
//     v[x][y] = 'x' ;
//     for (size_t i = 0; i < v.size(); i++)
//     {
//         for (size_t j = 0; j < v[0].size(); j++)
//         {
//             for (size_t k = 0; k < 8; k++) {
//                 int sx = x + dx[k] , sy = y + dy[k] ;
//                 while (sx>=0 && sy >= 0 && sx <= v.size()-1 && sy <= v[0].size()-1)
//                 {
//                     if (v[sx][sy] == '.'){
//                         v[sx][sy] = '#' ;
//                     }
//                     sx += dx[k] ;
//                     sy += dy[k] ;
//                 }
//                 sx = x+ horse[k][0] , sy = y +horse[k][1] ;
//                 if (sx>=0 && sy >= 0 && sx <= v.size()-1 && sy <= v[0].size()-1) {
//                     if (v[sx][sy] == '.'){
//                         v[sx][sy] = '#' ;
//                     }                    
//                 }
//             }
            
//         }
        
//     }
// }

// int check(vector<vector<char>>& v){
//     int count = 0 ;
//     for (size_t i = 0; i < v.size(); i++) {
//         for (size_t j = 0; j < v[0].size(); j++) {
//             if (v[i][j] == '.'){
//                 return 0 ;
//             } else if (v[i][j] == 'x') {
//                 count++;
//             }
//         }
//     }
//     return count ;
// }

// int cal_heu(vector<vector<char>>& v){
//     int count = 0 ;
//     for (size_t i = 0; i < v.size(); i++) {
//         for (size_t j = 0; j < v[0].size(); j++) {
//             if (v[i][j] == '.' || v[i][j] == 'x'){
//                 count++ ;
//             }
//         }
//     }
//     return count ;
// }

// int main(){
//     int n,m ; cin >> n >> m ;
//     vector<vector<char>> v(n,vector<char> (m)) ;
//     for (size_t i = 0; i < n; i++){
//         for (size_t j = 0; j < m; j++){
//             cin >> v[i][j] ;
//         }
//     }
//     priority_queue<pair<int,vector<vector<char>> >, vector<pair<int,vector<vector<char>> >>, greater<pair<int,vector<vector<char>> >> >pq ;
//     pq.push({cal_heu(v),v}) ;
//     while (!pq.empty())
//     {
//         auto [heu,vv] = pq.top() ; pq.pop() ;
//         for (size_t i = 0; i < n; i++)
//         {
//             for (size_t j = 0; j < m; j++)
//             {
//                 if (vv[i][j] == 'x' || v[i][j] == '#' ) {
//                     continue;
//                 } else {
//                     vector<vector<char>> copv(vv);
//                     change(copv,i,j);
//                     int ans = check(copv);
//                     if (ans){
//                         // cout << ans << "\n";
//                         for (size_t b = 0; b < n; b++)
//                         {
//                             for (size_t a = 0; a < m;a ++)
//                             {
//                                 if (copv[b][a] == 'x'){
//                                     cout << 'X' ;
//                                 } else {
//                                     cout << v[b][a] ;
//                                 }
//                             }
//                             cout << "\n" ;
//                         }
//                         return 0 ;
//                     }
//                     pq.push({cal_heu(copv),copv});
//                 }
//             }
//         }
//     }
// }