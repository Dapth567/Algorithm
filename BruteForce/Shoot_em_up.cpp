#include <bits/stdc++.h>

using namespace std ;
int n , w ;

void recur_fly(int count,int pos,string move){
    if (pos == 0 || pos > w){
        return ;
    }

    if (count == n){
        cout << move << endl;
        return ;
    }
    count++;
    recur_fly(count,pos-1,move+"D");
    recur_fly(count,pos,move+"S");
    recur_fly(count,pos+1,move+"U");
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int b ;
    string move = "" ;
    cin >> n >> w >> b ;
    recur_fly(0,b,move) ;
}

#include <bits/stdc++.h> 
using namespace std;
int n,w,b;
void r(string s,int h) {
    if(s.size() == n) {
        cout << s << '\n';
        return ;
    }
    if(h-1>0) r(s+'D',h-1);
    r(s+'S',h);
    if(h+1<=w) r(s+'U',h+1);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> w >> b;
    r("",b);
}