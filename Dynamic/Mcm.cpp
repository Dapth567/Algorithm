// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// // ฟังก์ชันหาค่าการคูณที่น้อยที่สุด
// int matrixChainOrder(int p[], int n) {
//     // m[i][j] เก็บจำนวนครั้งในการคูณ scalar ที่น้อยที่สุดสำหรับเมทริกซ์ Ai...Aj
//     int m[n][n];

//     // ค่าใช้จ่ายจะเป็น 0 ถ้าคูณเมทริกซ์ตัวเดียว
//     for (int i = 1; i < n; i++)
//         m[i][i] = 0;

//     // L คือความยาวของ chain (เริ่มจากคูณ 2 ตัว, 3 ตัว, ... จนถึง n-1 ตัว)
//     for (int L = 2; L < n; L++) {
//         for (int i = 1; i < n - L + 1; i++) {
//             int j = i + L - 1;
//             m[i][j] = INT_MAX;

//             // ลองแบ่งจุดคูณที่ k ต่างๆ เพื่อหาค่าที่น้อยที่สุด
//             for (int k = i; k <= j - 1; k++) {
//                 int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
//                 if (q < m[i][j])
//                     m[i][j] = q;
//             }
//         }
//     }

//     return m[1][n - 1];
// }

// int main() {
//     int n ; cin >> n ;
//     int arr[n+1] ;
//     for (size_t i = 0; i < n+1; i++)
//     {
//         cin >> arr[i];
//     }
    
//     int size = sizeof(arr) / sizeof(arr[0]);

//     cout << matrixChainOrder(arr, size) << endl;

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std ;

int mcm(int a[],int n){
    int m[n][n] = {0};
    for (size_t l = 2; l < n; l++)
    {
        for (size_t i = 1; i < n - l + 1 ; i++)
        {
            int j = i + l - 1 ;
            m[i][j] = INT_MAX ;
        }
        
    }
    
    
}

int main(){
    int n ; cin >> n ;
    int a[n+1];
    for (size_t i = 0; i < n+1; i++)
    {
        cin >> a[i];
    }
    cout << mcm(a,n+1) ;
}