#include <bits/stdc++.h>

using namespace std ;

int n ;
set<string> bad_word_list ;
vector<string> ans ;

void abc_generate(int count , string word , string last_alphabet,int a ,int b ,int c){

    if (count == n) {
        ans.push_back(word);
        return ;
    }

    if (a > 0 && bad_word_list.find(last_alphabet+"A") == bad_word_list.end()){
        abc_generate(count+1 , word+"A" , "A",a-1,b,c);
    }

    if (b > 0 && bad_word_list.find(last_alphabet+"B") == bad_word_list.end()){
        abc_generate(count+1 , word+"B" , "B",a,b-1,c);
    }

    if (c > 0 && bad_word_list.find(last_alphabet+"C") == bad_word_list.end()){
        abc_generate(count+1 , word+"C" , "C",a,b,c-1);
    }

    return ;
}


int main() {

    int bad_word_amount,a,b,c ;
    string badword , word = "" , last_alphabet = "x";
    
    cin >> n >> a >> b >> c ;
    cin >> bad_word_amount ;
    

    while (bad_word_amount--)
    {
        cin >> badword;
        bad_word_list.insert(badword);
    }
    
    abc_generate(0,word,last_alphabet,a,b,c) ;

    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl ;
    }
    
}