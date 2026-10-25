#include <bits/stdc++.h>
using namespace std ;
int parent(int a , vector<int>& disj){
    while (disj[a] != -1)
    {
        a = disj[a] ;
    }
    return a ;
}
void uni(int a ,int b ,vector<int>& disj){
    a = parent(a,disj);
    b = parent(b,disj);
    if (a == b){
        return ;
    } else {
        disj[b] = a ;
    }
}
int main(){
    int v ,total_w = 0;
    cin >> v ;
    vector<int> disj(v,-1);
    vector<tuple<int,int,int>> edge ;
    for (size_t i = 0; i < v; i++)
    {
        for (size_t j = i+1; j < v; j++)
        {
            int x ; cin >> x ; edge.push_back({x,i,j});
        }
    }
    sort(edge.begin(),edge.end());
    for (auto [w,u,v] : edge)
    {
        if (parent(u,disj) != parent(v,disj)){
            uni(u,v,disj);
            total_w += w ;
        }
    }
    cout << total_w ;
}