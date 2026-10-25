#include <bits/stdc++.h>

using namespace std ;
map<int,int> value_amount ,stack_value;
vector<pair<int,int>> sum_count ;



int main(){
    int n,q,value,amount,stack=0;
    cin >> n >> q ;

    while(n--)
    {
        cin >> value >> amount ;
        if (value_amount.find(value) == value_amount.end()){   
            value_amount[value] = amount ;
        } else {
            value_amount[value] += amount ;
        }
        
    }

    for (auto it = value_amount.begin(); it!= value_amount.end() ; it++){
        stack += it->second ;
        stack_value[stack] = it->first ;
    }
   
    while(q--)
    {
        cin >> amount ;
        auto it1 = stack_value.lower_bound(amount);
        cout << it1->second << endl;
    }
    
}