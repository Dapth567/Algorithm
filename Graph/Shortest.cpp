#include <bits/stdc++.h>

using namespace std ;

int final_ans = INT_MAX,curren_shortest = INT_MAX ;

bool inbound(vector<string>& map ,pair<int,int> direction){
    int r = direction.first , c = direction.second ;
    return (r >= 0 && r <= map.size()-1 && c >= 0 && c <= map[r].size()-1) ;
}

void find_path(int r,int c,vector<string>& map, int& ans,vector<vector<bool>>& visit,bool& found){
    // vector<int> val_row(map[r].size(),0);
    // vector<vector<int>> checkmap(map.size(),) ;
    set<pair<int,pair<int,int>>> order ;
    order.insert({0,{r,c}});
    visit[r][c] = true ;
    int step = 0 ;
    while (!found && order.size() != 0)
    {
        auto it = order.begin() ; 
        step = it->first ;
        int rx = (it->second).first , cx = (it->second).second ;
        pair<int,int> up = {rx+1,cx} , down = {rx-1,cx} , left = {rx,cx-1} , right = {rx,cx+1} ;
        
        if (inbound(map,up) && map[up.first][up.second] == '.' && visit[up.first][up.second] == false){
            visit[up.first][up.second] = true ;
            order.insert({step+1,up});
        }
        if (inbound(map,down) && map[down.first][down.second] == '.' && !visit[down.first][down.second] ){
            visit[down.first][down.second] = true ;
            order.insert({step+1,down});
        }
        if (inbound(map,left) && map[left.first][left.second] == '.' && !visit[left.first][left.second]){
            visit[left.first][left.second] = true ;
            order.insert({step+1,left});
        }
        if (inbound(map,right) && map[right.first][right.second] == '.' && !visit[right.first][right.second]){
            visit[right.first][right.second] = true ;
            order.insert({step+1,right});
        }
        order.erase(it);
        if (visit[map.size()-1][map[0].size()-1]){
            final_ans = step+1 ;
            return ;
        }
    }
    
}

int main() {
    int c , r , ans = 0;
    string row ;
    cin >> r >> c ;
    vector<string> map ;
    bool found = false ;
    vector<bool> vis_row(c,false) ;
    vector<vector<bool>> visit(r,vis_row);
    for (size_t i = 0; i < r; i++)
    {
        cin >> row ;
        map.push_back(row);
    }
    find_path(0,0,map,ans,visit,found);

    if (final_ans == INT_MAX){
        cout << -1 ;
    }else {
        cout << final_ans ;
    }
    
}