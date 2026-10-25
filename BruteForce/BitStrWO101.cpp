#include <bits/stdc++.h>
#define ll long long
using namespace std ;
ll ans ;
ll mod = 100000007 ;
void count_have101(ll& n,int count, string last_dig){

    if (count == n){
        ans += 1 ;
        return ;
    }

    if(count < 2){
    count_have101(n,count+1,last_dig+"0");
    count_have101(n,count+1,last_dig+"1");        
    } else {
        if(last_dig != "10" ){
            if(last_dig == "00"){
                count_have101(n,count+1,last_dig);
                count_have101(n,count+1,"01");
            } else if (last_dig == "01") {
                count_have101(n,count+1,"10");
                count_have101(n,count+1,"11");
            } else if (last_dig == "11") {
                count_have101(n,count+1,"10");
                count_have101(n,count+1,last_dig);            
            }
        } else {
            count_have101(n,count+1,"00");
        }
    }



    
}

int main(){
    ll n ;
    cin >> n ;
    count_have101(n,0,"");
    cout << ans % mod ;

}