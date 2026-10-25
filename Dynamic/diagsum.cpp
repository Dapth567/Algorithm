#include <bits/stdc++.h>

using namespace std ;

void add_prev_diag(int i,int j,vector<vector<int>>& table,int value){
    if ( i - 1 >= 0 && j - 1 >= 0){
        table[i-1][j-1] += value ;
        add_prev_diag(i-1,j-1,table,value);
    } else {
        return ;
    }
}

int main() {
    int s,count,ans= INT_MIN ;
    cin >> s ;
    vector<int> row(s,0);
    vector<vector<int>> table(s,row) ;
    for (size_t i = 0; i < s; i++) {
        for (size_t j = 0; j < s; j++) {
            cin >> table[i][j];
            if (i > 0 && j > 0){
                add_prev_diag(i,j,table,table[i][j]);
            }
        }
    }
    for (size_t i = 0; i < s; i++)
    {
        for (size_t j = 0; j < s; j++)
        {
            cout << table[i][j] << " ";
            ans = max(ans ,table[i][j]);
        }
        cout << "\n";
    }
    cout << ans ;
    
    
}