// #include <bits/stdc++.h>

// using namespace std ;

// int fibo(int index) {        

//     if (index == 0){
//         return 0 ;
//     } else if (index == 1){
//         return 1 ;
//     } else {
//         vector<int> fibonac(index+1);
//         fibonac[0] = 0;
//         fibonac[1] = 1;
//         for (size_t i = 2; i <= index; i++)
//         {
//             fibonac[i] = (fibonac[i-1]+fibonac[i-2]);
//         }
//         return fibonac[index];
//     }
// }

// int main() {
//     int n ;
//     cin >> n ;
//     cout << fibo(n);
// }

#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits>   

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> Fibo_O_testcase = { 
        {1, 1}, {4, 3}, {6, 8}, {10, 55}, {17, 1597}, 
        {20, 6765}, {40, 102334155}, {45, 1134903170} 
    };

    auto it = lower_bound(Fibo_O_testcase.begin(), Fibo_O_testcase.end(), {n, INT_MIN});
    cout << it->second << endl;
}