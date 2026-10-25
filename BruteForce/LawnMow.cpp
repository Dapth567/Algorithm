#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n , m , k ,grass_amount, grass_stack = 0,budget,start;
    vector<int> stack_grass,each_block ;
    cin >> n >> m >> k ;
    for (size_t i = 0; i < n; i++)
    {
        cin >> grass_amount ;
        each_block.push_back(grass_amount) ;
        grass_stack += grass_amount ;
        stack_grass.push_back(grass_stack);
    }

    for (size_t i = 0; i < m; i++)
    {
        cin >> start >> budget ;

        for (size_t j = start; j < n; j++)
        {
            if (stack_grass[start] == stack_grass[j]){
                if (each_block[j] + 1 >= budget){
                    cout << each_block[j] << "\n";
                } else {
                    cout << 0 << "\n";
                }
            } else {
                if (start == 0 ){

                } else{

                }
            }
        }
        
    }
    
    
}