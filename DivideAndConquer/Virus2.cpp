#include <bits/stdc++.h>

using namespace std ;

int check(vector<int>& pos, bool& legit,int start,int stop,int count){
    if(legit){
        if (start == stop) {
            count += pos[start];
            return count ;
        }
        int m = (start+stop) / 2 ;
        int a = check(pos,legit,start,m,count);
        int b = check(pos,legit,m+1,stop,count);
        if (abs(a-b) > 1){
            legit = false ;
        }
        return (a+b) ; 
    }else {
        return 0 ;
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n , k ;
    cin >> n >> k ;
    while (n--)
    {
        vector<int> pos (pow(2,k)) ;
        bool legit = true ;
        for (size_t i = 0; i < pos.size(); i++){
            cin >> pos[i] ;
        }
        int x = check(pos,legit,0,pos.size()-1,0);
        if (!legit){
            cout << "no\n" ;
        } else {
            cout << "yes\n" ;
        }
    }
    
}