#include <bits/stdc++.h>

using namespace std ;

int main() {
    int r , c , n ,sum = 0,value;
    cin >> r >> c >> n ;
    vector<int> row(c,0) ;
    vector<vector<int>> table(r,row) ;
    for (size_t i = 0; i < r; i++)
    {
        sum = 0 ;
        for (size_t j = 0; j < c; j++)
        {
            cin >> value ;
            sum += value ;
            table[i][j] = sum ;
        }
    }

    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            cout << table[i][j] << " " ;
        }
        cout << "\n" ;
    }

    int r1 , c1 , r2 , c2 ;
    while (n--)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        sum = 0 ;
        for (size_t i = r1; i <= r2; i++)
        {
            if (c1 == 0){
                sum += table[i][c2];
            } else {
                sum += table[i][c2] - table[i][c1-1] ;
            }
        }
        cout << sum << "\n";
        
    }
    
}