#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n ,value;
    cin >> n ;
    vector<int> current_max(n,0) ;
    for (size_t i = 0; i < n; i++){
        vector<int> new_cur_max(current_max);
        for (size_t j = 0; j < i+1; j++){
            cin >> value ;
            if (j == 0){
                new_cur_max[j] = max(current_max[j] + value, value);
            } else if (j == i) {
                new_cur_max[j] = max(current_max[j-1] + value, value);
            } else {
                new_cur_max[j] = max({current_max[j]+ value,current_max[j-1]+ value, value});
            }
        }
        current_max = new_cur_max ;
    }


    int ans = INT_MIN ;
    for (size_t i = 0; i < current_max.size(); i++)
    {
        ans = max(ans,current_max[i]);
    }
    cout << ans ;
}