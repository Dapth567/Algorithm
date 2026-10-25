#include <bits/stdc++.h>

using namespace std;

void make_zero(int value,int& count,bool& found,queue<int>& possible){
    if (!found){
        int round = possible.size();
        int value ;
        count += 1 ;
        for (size_t i = 0; i < round ; i++)
        {
            
            value = possible.front() ; possible.pop() ;

            if ((value + 1) % 16777216 != 0){
                possible.push((value + 1) % 16777216) ;
            } else {
                found = true ;
                cout << count ;
                break;
            }

            if ((value * 2) % 16777216 != 0){
                possible.push((value * 2) % 16777216) ;
            } else {
                found = true ;
                cout << count ;
                break;
            }
            
        }
        if (!found){
            make_zero(value,count,found,possible);
        }
    }

}

int main() {
    bool found = false ;

    queue<int> out_put ;
    int value,count = 0 ;
    cin >> value ;
    out_put.push(value);
    if (value == 0){
        cout << 0 ;
    } else {
        make_zero(value,count,found,out_put);
    }
    
}