#include <bits/stdc++.h>

using namespace std ;

bool legit(vector<int>& pos_out_come,int start,int stop){

    if (start + 1 == stop){ 
        if (pos_out_come[start] == 0 && pos_out_come[stop] == 1){
            return true ;
        } else {
            return false ;
        }
    }

    int m = (start + stop)/2 ;

    if (pos_out_come[m] == 0 ){
        reverse(pos_out_come.begin()+start , pos_out_come.begin() + m + 1) ;  
    }

    if (legit(pos_out_come,start,m) && legit(pos_out_come,m+1,stop)){
        return true ;
    } else {
        return false ;
    }

}

int main() {

    int n , k ,value;
    vector<string> ans ;
    cin >> n >> k ;

    while (n--){
        vector<int> pos_out_come;
        for (size_t i = 0; i < pow(2,k); i++){
            cin >> value ;
            pos_out_come.push_back(value);
        }

        if(legit(pos_out_come,0,pos_out_come.size()-1)) {
            ans.push_back("yes\n") ;
        } else {
            ans.push_back("no\n") ;
        }
    }    
    for(string x : ans ){
        cout << x ;
    }
}


//compact ver
// #include <bits/stdc++.h>

// using namespace std ;

// bool legit(vector<int>& pos_out_come,int start,int stop){
//     if (start + 1 == stop){ 
//       return (!pos_out_come[start] && pos_out_come[stop]) ;
//     }
//     int m = (start + stop)/2 ;
//     if (!pos_out_come[m]){
//         reverse(pos_out_come.begin()+start , pos_out_come.begin() + m + 1) ;  
//     }
//     return (legit(pos_out_come,start,m) && legit(pos_out_come,m+1,stop)) ;
// }

// int main() {

//     int n , k ,value;
//     vector<string>ans ;
//     cin >> n >> k ;

//     while (n--){
//         vector<int> pos_out_come(pow(2,k));
//         for (size_t i = 0; i < pos_out_come.size(); i++){
//             cin >> pos_out_come[i] ;
//         }
//         if(legit(pos_out_come,0,pos_out_come.size()-1)) {
//             cout << "yes\n" ;
//         } else {
//             cout << "no\n" ;
//         }
//     }    
// }

