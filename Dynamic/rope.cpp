// #include <bits/stdc++.h>

// using namespace std ;

// void long_rope(int goal,int count,int& a,int &b,int& c ,bool& find){
//     if(!find){
//         if(goal < 0){
//             return ;
//         }
//         if(goal == 0){
//             cout << count ;
//             find = true ;
//             return ;
//         }
//         long_rope(goal-a,count+1,a,b,c,find);
//         long_rope(goal-b,count+1,a,b,c,find);
//         long_rope(goal-c,count+1,a,b,c,find);
//     } else {
//         return ;
//     }
// }

// int main() {
//     int goal ;
//     vector<int> v(3);
//     bool find = false ;
//     cin >> goal ;
//     for (size_t i = 0; i < 3; i++)
//     {
//         cin >> v[i];
//     }
//     sort(v.begin(),v.end());
//     int a = v[0],b=v[1],c=v[2];
//     long_rope(goal,0,a,b,c,find);
// }

#include <bits/stdc++.h>

using namespace std ;
int main(){
    int goal  ; cin >> goal  ;
    vector<int> coins(3) ;
    for (size_t i = 0; i < 3; i++)
    {
        cin >> coins[i] ;
    }
    vector<int> count(goal+1,INT_MIN) ;
    count[0] = 0 ;
    for (int i = 1; i <= goal; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i - coins[j] >= 0 && count[i - coins[j]] != INT_MIN){
                count[i] = max(count[i],count[i-coins[j]] + 1) ;
            }
        }
        
    }
    cout << count[goal] ;
}