#include <bits/stdc++.h>

using namespace std ;

void my_recur(int n ,int a, int b ,int c, string word, vector<string>& ans){
    if (n > 0){
        if(a > 0){
            my_recur(n-1 ,a-1 ,b ,c ,word + "A" ,ans);
        }
        if(b > 0){
            my_recur(n-1 ,a ,b-1 ,c ,word + "B" ,ans);
        }
        if(c > 0){
            my_recur(n-1 ,a ,b ,c-1 ,word + "C" ,ans);
        }                
    } else {
        ans.push_back(word);
    }
}

int main(){
    
    vector<string> ans ;
    string empt = "";
    int n , a , b , c ;
    cin >> n >> a >> b >> c ;
    my_recur(n,a,b,c,empt,ans);
    cout << ans.size() << endl;
    for (auto it : ans){
        cout << it << endl;
    }

}