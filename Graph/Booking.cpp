#include <iostream>
#include <vector>
#include <set>

using namespace std ;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n , m , am ; cin >> n >> m ;
    set<pair<string,string>> ticket ;
    string a , b ;
    for (size_t i = 0; i < n; i++) {
        cin >> a >> b ;
        ticket.insert({a,b}) ;
    }
    for (size_t i = 0; i < m; i++) {
        cin >> am ; bool error = false ;
        vector<pair<string,string>> to_reserve(am) ;
        for (size_t j = 0; j < am; j++) {
            cin >> a >> b ;
            if (!error){
                to_reserve[j] = {a,b} ;
                if (ticket.find({a,b}) == ticket.end()){
                    error = true ;
                }
            }
        }
        if (error) {
            cout << "NO\n" ;
        } else {
            for (auto &x : to_reserve) {
                ticket.erase(x) ;
            }
            cout << "YES\n" ;
        } 
    }
}