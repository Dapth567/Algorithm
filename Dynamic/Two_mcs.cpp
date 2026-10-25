#include <bits/stdc++.h>

using namespace std ;

void maxSubArraySum(vector<int>& nums , vector<int>& a) {
    int max_so_far = INT_MIN; 
    int current_max = 0;
    
    for (size_t i = 0; i < nums.size()-1; i++)
    {
        current_max = max(nums[i], current_max + nums[i]);
        max_so_far = max(max_so_far, current_max);
        a[i] = max_so_far ;
    }
    
}

int main() {
    int n ;
    cin >> n ;
    vector<int> v(n) ,forward(n-1),backward(n-1);
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i] ;
    }
    vector<int> v_r(v);
    reverse(v_r.begin(),v_r.end());
    maxSubArraySum(v,forward);
    maxSubArraySum(v_r,backward);
    int ans = INT_MIN ;
    for (size_t i = 0; i < n-1; i++)
    {
        int r = forward[i] + backward[backward.size()-1-i];
        ans = max(r,ans);
    }
    cout << ans ;
}