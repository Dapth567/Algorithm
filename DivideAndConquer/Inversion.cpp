#include <bits/stdc++.h>



int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    size_t count = 0 , n ;
    std::cin >> n ;
    std::vector<int> u(n) ;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> u[i] ;
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if(u[i] > u[j]) count++;
        }
        
    }
    std::cout << count ;
    
    

}