






























// #include <bits/stdc++.h>
// #define ll long long 
// using namespace std ;

// int count_left(ll q,priority_queue<pair<ll,ll>> T){
//     ll ans = 0, value , time ;
//     pair<ll,ll> this_q ;
//     while(q != 0){

//         this_q = T.top(); T.pop() ;
//         value = this_q.first ;
//         time = this_q.second ;

//         ans = max(ans, -(value));
//         value -= time ;
        

//         T.push(make_pair(value,time));
//         q--;
//     }
//     return ans ;
// }

// int main() {
//     ll n , a , time , LCM = 1 , q_per_round = 0 , q ;
//     priority_queue<pair<ll,ll>> T ;
//     vector<int> each_time ;
//     cin >> n >> a ;
//     for (size_t i = 0; i < n; i++)
//     {
//         cin >> time ;
//         T.push(make_pair(0,time));
//         each_time.push_back(time);
//         LCM = lcm(LCM,time);
//     }
    
//     for (size_t i = 0; i < n; i++)
//     {
//         q_per_round += (LCM / each_time[i]) ;
//     }
    
//     for (size_t i = 0; i < a; i++)
//     {
//         ll dis_q = 0 ;
//         cin >> q ;
//         if (q / LCM > 0){
//             dis_q += LCM*(q/q_per_round) ;
//             q = q % q_per_round ;
//             dis_q += count_left(q,T);
//         } else {
//             dis_q += count_left(q,T);
//         }
//         cout << dis_q % 100000007 << "\n" ;
//     }
    
// }