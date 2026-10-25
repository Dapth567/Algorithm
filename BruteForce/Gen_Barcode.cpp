#include <bits/stdc++.h>

using namespace std ;

int a,b ;

void generated_bar(string barcode,int count){
    if (b != barcode.size()){
        if (count < a ){
            generated_bar(barcode+"0",count);
            generated_bar(barcode+"1",count+1);
        } else {
            generated_bar(barcode+"0",count) ;
        }
    } else if (count == a){
        cout << barcode << endl;
    }
}

int main(){
    string barcode = "" ;
    cin >> a >> b ;
    generated_bar(barcode,0);
}