#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n,m,value ;
    cin >> n >> m ;
    vector<int> arr;

    for (size_t i = 0; i < n; i++)
    {
        cin >> value ;
        arr.push_back(value) ;
    }

    for (size_t i = 0; i < m; i++)
    {
        int count = 0 ;
        cin >> value ;
        for (size_t j = 0; j < n; j++)
        {
            if (arr[j] > value){
                count += 1 ;
            } else if (arr[j] == value){
                cout << count << endl;
                break;
            }
        }
    }
    
    
}