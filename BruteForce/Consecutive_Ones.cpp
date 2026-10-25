#include <bits/stdc++.h>

using namespace std;

int length , consecutive ;

void generated_consec(string binary, int streak){
    if (binary.size() != length){
        if (streak == consecutive){
            generated_consec(binary + "0" , streak);
            generated_consec(binary + "1" , streak);
        } else {
            generated_consec(binary + "0" , 0);
            generated_consec(binary + "1" , streak+1);

        }
    } else if ( streak == consecutive ){
        cout << binary << endl;
    }
}

int main(){
    string binary = "";
    cin >> length >> consecutive ;
    generated_consec(binary,0);
}