#include <bits/stdc++.h>

using namespace std ;

vector<vector<int>> matrix_mod( vector<vector<int>>& matrix,int n,int& k1){

    if (n == 1) {
        vector<vector<int>> m1 = matrix ;
        vector<vector<int>> ans ;
        for (size_t i = 0; i < 2; i++)
        {
            vector<int> row ;
            for (size_t j = 0; j < 2; j++){
                row.push_back(m1[i][j] % k1) ;
            }
            ans.push_back(row);
        }
        return ans ;
    }

    if (n%2 == 0 ){
        vector<vector<int>> m1 = matrix_mod(matrix,n/2,k1) , m2 = m1 ;
        vector<vector<int>> ans ;
        for (size_t i = 0; i < 2; i++)
        {
            vector<int> row ;
            for (size_t j = 0; j < 2; j++){
                int grid = 0 ;
                for (size_t k = 0; k < 2; k++)
                {
                    grid += (m1[i][k] * m2[k][j]) ;
                    grid %= k1 ;
                }
                row.push_back(grid);
            }
            ans.push_back(row);
        }
        return ans ;
    } else {
        vector<vector<int>> m1 = matrix_mod(matrix,n/2,k1) , m2 = m1 ;
        vector<vector<int>> ans ;
        for (size_t i = 0; i < 2; i++)
        {
            vector<int> row ;
            for (size_t j = 0; j < 2; j++){
                int grid = 0 ;
                for (size_t k = 0; k < 2; k++)
                {
                    grid += (m1[i][k] * m2[k][j]);
                    grid %= k1 ;
                }
                row.push_back(grid);
            }
            ans.push_back(row);
        }

        vector<vector<int>> ans1 ,  m3 = matrix_mod(matrix,1,k1);
        for (size_t i = 0; i < 2; i++)
        {
            vector<int> row ;
            for (size_t j = 0; j < 2; j++){
                int grid = 0 ;
                for (size_t k = 0; k < 2; k++)
                {
                    grid += (ans[i][k] * m3[k][j]) ;
                    grid %= k1 ;
                }
                row.push_back(grid);
            }
            ans1.push_back(row);
        }
        return ans1 ;
    }
}


int main() {
    int n , k , value ;
    vector<vector<int>> matrix ;
    cin >> n >> k ;

    for (size_t i = 0; i < 2; i++)
    {
        vector<int> row ;
        for (size_t j = 0; j < 2; j++)
        {
            cin >> value ;
            row.push_back(value);
        }
        matrix.push_back(row) ;
    }

    vector<vector<int>> ans = matrix_mod(matrix,n,k);
    for(vector<int> row : ans){
        for(int x : row){
            cout << x << " ";
        }
    }
}