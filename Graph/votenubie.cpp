#include <bits/stdc++.h>

using namespace std ;

int main(){
    int n , k ;
    cin >> n >> k ;
    string name ;
    map<string,int> candidate ;
    priority_queue<pair<int,string>> top_vote;
    for (size_t i = 0; i < n; i++)
    {
        cin >> name ;
        candidate[name]++;
    }
    for (auto it : candidate)
    {
        top_vote.push({it.second,it.first});
    }
    int current_min = INT_MAX ;
    for (size_t i = 0; i < k; i++)
    {
        if (!top_vote.empty()){
            current_min = min(current_min,top_vote.top().first) ;
            top_vote.pop();
        }
    }
    cout << current_min ;
    
    
}