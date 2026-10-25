#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n,sum = 0 ,left= 0 ,right,focus_idx;
    cin >> n ;
    vector<int>v(n,0) , v_cop(n,0);
    map<int,int> m ;
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    v_cop = v ;
    right = sum ;
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (size_t i = 0; i < n; i++)
    {
        right -= v[i] ;
        left += v[i] ;
        if(left > right){
            focus_idx = i ;
            break; 
        }
    }
    cout << focus_idx + 1 << "\n";
    for (int i = focus_idx; i >= 0 ; i--)
    {
        if (m.find(v[i]) == m.end()){
            m[v[i]] = 1 ;
        } else {
            m[v[i]] += 1 ;
        }
        
    }
    for (size_t i = 0; i < n; i++)
    {
        if (m.find(v_cop[i]) != m.end() && m[v_cop[i]] > 0){
            m[v_cop[i]]--;
            cout << i+1 << " " ;
        }
    }
    
    
    
}

