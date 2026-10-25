#include <bits/stdc++.h>

using namespace std ;
int a , n ,value;

int main() {
    vector<int> value_list ;
    map<int,vector<pair<int,int>>> value_idx_pair ;
    cin >> a >> n ;
  
    for(int i = 0 ; i < a ;i++){
        cin >> value ;
        value_list.push_back(value);
    }

    for (size_t i = 0; i < a; i++){
        for (size_t j = i + 1; j < a; j++){
            int val_i = value_list[i] , val_j = value_list[j];
            value_idx_pair[val_i + val_j].push_back(make_pair(i,j)) ;
        }
    }
    
    for (size_t i = 0; i < n; i++)
    {
        cin >> value ;
        bool found = false ;
        for (size_t i = 0; i < a; i++)
        {
            if (value_idx_pair.find(value - value_list[i]) != value_idx_pair.end()){
               for (auto it = value_idx_pair[value - value_list[i]].begin() ; it != value_idx_pair[value - value_list[i]].end() ; it++){
                    if (i != it->first && i != it->second){
                        found = true ;
                        break;
                    }
               }
            }
        }
        if(found){
            cout << "YES\n"  ;
        } else {
            cout << "NO\n" ;
        }
        
    }
    
}