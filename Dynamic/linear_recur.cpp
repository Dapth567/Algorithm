#include <bits/stdc++.h>

using namespace std ;


int main() {
    int n,k;
    cin >> k >> n ;
    vector<int> a(k),r(n+1,0),c(k);
    for (size_t i = 0; i < k; i++)
    {
        cin >> c[i];
        c[i] %= 32717 ;
    }
    for (size_t i = 0; i < k; i++)
    {
        cin >> r[i];
    }


    for (size_t i = k; i <= n; i++)
    {
        for (size_t j = 0; j < k; j++)
        {
            // cout << c[j] << " x " << r[i-j-1] << " = " << (c[j] * r[i - j - 1]) << "\n" ;
            r[i] += (c[j] * r[i - j - 1]) % 32717 ;
            r[i] %= 32717 ;  
        }    
    }
    cout << r[n] ;
    
}