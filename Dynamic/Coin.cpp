#include <bits/stdc++.h>

using namespace std ;
const int inf = 1e8 ;
int main() {
    int n , m ; cin >> n >> m ;
    vector<int> coin(n);
    for (size_t i = 0; i < n; i++) {
        cin >> coin[i] ;
    }
    vector<int> dp(m+1,inf) ;
    dp[0] = 0 ;
    for (size_t i = 1; i <= m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i - coin[j] >= 0 ) {
                if (dp[ i - coin[j]] != inf) {
                    dp[i] = min(dp[i],dp[ i - coin[j] ] + 1);
                }
                
            }
        }   
    }
    // for (auto num : coin)
    // {
    //     cout << num << " " ;
    // }
    
    cout << dp[m] ;
}


// #include <bits/stdc++.h>
// using namespace std;

// // ใช้ค่าที่มากพอแต่ไม่ทำให้เกิด Overflow เมื่อ +1
// const int inf = 1e8; 

// int main() {
//     int n, m; 
//     if (!(cin >> n >> m)) return 0;

//     vector<int> coins(n);
//     for (int i = 0; i < n; i++) {
//         cin >> coins[i];
//     }

//     // แก้จุดที่ 1: ตั้งค่าเริ่มต้นเป็นค่ามาก (inf)
//     vector<int> dp(m + 1, inf);
    
//     // แก้จุดที่ 2: Base case เงิน 0 บาท ใช้ 0 เหรียญ
//     dp[0] = 0;

//     for (int i = 1; i <= m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (i - coins[j] >= 0) {
//                 // ถ้าค่าก่อนหน้าทอนได้ (ไม่ใช่ inf) ให้ลองบวกเหรียญนี้เพิ่ม 1
//                 if (dp[i - coins[j]] != inf) {
//                     dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//                 }
//             }
//         }
//     }

//     // แสดงคำตอบสุดท้ายตามตัวอย่างโจทย์ [cite: 16]
//     cout << dp[m] << endl;

//     return 0;
// }