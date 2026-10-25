#include <bits/stdc++.h>

using namespace std ;

void recur_tower(vector<int>& tower,map<int,int> mon_pow,int range,int total_hp,int tow_count,int& ans){

    if (tow_count == tower.size()){
        ans = min(ans,total_hp);
        return ;
    }
    bool shot_fired = false;
    for (auto it = mon_pow.begin(); it != mon_pow.end(); it++)
    {
        int pos = it->first ;
        if (pos >= tower[tow_count] - range && pos <= tower[tow_count] + range){
            map<int,int> copy_mon_pow = mon_pow ;
            copy_mon_pow[pos]--;
            if (copy_mon_pow[pos] == 0){
                copy_mon_pow.erase(pos);
            }
            shot_fired = true ;
            recur_tower(tower,copy_mon_pow,range,total_hp-1,tow_count+1,ans);
            break;
        }
    }
    if (!shot_fired){
        recur_tower(tower,mon_pow,range,total_hp,tow_count+1,ans);
    }
}


int main(){
    int n , m ,k, w ,pos,pow,total_hp = 0;
    cin >> n >> m >> k >> w ;
    vector<int> mon_pos_list ;
    map<int,int> mon_pow ;
    vector<int> tower ;
    
    for (size_t i = 0; i < m; i++)
    {
        cin >> pos ;
        mon_pos_list.push_back(pos);
    }

    for (size_t i = 0; i < m; i++)
    {
        cin >> pow ;
        if(mon_pow.find(mon_pos_list[i]) == mon_pow.end()){
            mon_pow[mon_pos_list[i]] = pow ;
        } else {
            mon_pow[mon_pos_list[i]] += pow ;
        }
        total_hp += pow ;
    }

    for (size_t i = 0; i < k; i++)
    {
        cin >> pos ;
        tower.push_back(pos) ;
    }
    int ans = total_hp ;
    recur_tower(tower,mon_pow,w,total_hp,0,ans);
    cout << ans ;
    
    
    
    
}