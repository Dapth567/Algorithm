#include <bits/stdc++.h>

using namespace std ;
int n , m ;

int main(){
    cin >> n >> m ;
    int days,date;
    vector<vector<bool>> every_per(m) ;
    for (size_t i = 0; i < m; i++)
    {   
        vector<bool> each_per(n,false) ;
        cin >> days ;
        for (size_t i = 0; i < days; i++)
        {
            cin >> date ;
            each_per[date] = true ;
        }
        every_per.push_back(each_per) ;
    }
    
}