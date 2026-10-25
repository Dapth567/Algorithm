#include <bits/stdc++.h>

using namespace std ;
int r , c , cycle_detect = 0;

bool inbound(int row,int column){
    return (row >= 0 && row <= r-1 && column >= 0 && column <= c-1) ;
}

void create_direct_path(pair<int,int> from, pair<int,int> to,map<pair<int,int>,vector<pair<int,int>>>& path){
    if (inbound(to.first,to.second)){
        path[from].push_back(to);
    }
}

void create_path(int row,int column,int& command,map<pair<int,int>,vector<pair<int,int>>>& path ){
    switch (command)
    {
    case (1) :
        create_direct_path({row,column},{row,column-1},path);
        create_direct_path({row,column},{row,column+1},path);
        break;
    case (2) :
        create_direct_path({row,column},{row-1,column},path);
        create_direct_path({row,column},{row+1,column},path);
        break;
    case (3) :
        create_direct_path({row,column},{row-1,column},path);
        create_direct_path({row,column},{row,column+1},path);
        break;
    case (4) :
        create_direct_path({row,column},{row,column+1},path);
        create_direct_path({row,column},{row+1,column},path);
        break;
    case (5) :
        create_direct_path({row,column},{row+1,column},path);
        create_direct_path({row,column},{row,column-1},path);
        break;
    case (6) :
        create_direct_path({row,column},{row,column-1},path);
        create_direct_path({row,column},{row-1,column},path);
        break;
    default:
        break;
    }
}

bool check_visit(vector<int>& visit,pair<int,int> check){
    if (visit[((check.first)*c) + check.second] == -1){
        return false ;
    } else {
        return true ;
    }
}

void mark_visit(vector<int>& visit,pair<int,int> dot,int component){
    visit[(dot.first*c)+dot.second] = component ;
}

bool check_same_component(vector<int>& visit,pair<int,int> from , pair<int,int> v){
    if (visit[(from.first*c)+from.second] == visit[(v.first*c)+v.second]){
        return true ;
    } else {
        return false ;
    }
}

void dfs(int& count,int& component,map<pair<int,int>,vector<pair<int,int>>>& path,vector<int>& visit,pair<int,int> from,pair<int,int> parent){
    count++;
    if (parent == make_pair(-1,-1)){
        mark_visit(visit,from,component);
    } else {
        if (find(path[from].begin(),path[from].end(),parent) != path[from].end()){
            mark_visit(visit,from,component);
        } else {
            count = 0 ;
            return ;
        }
    }
    for (auto v : path[from])
    {
        if (!check_visit(visit,v)){
            dfs(count,component,path,visit,v,from);
        } else {
            if(check_same_component(visit,from,v)){
                cycle_detect++;
                count++;
                return ;
            } else {
                count = 0;
                return ;
            }
        }
    }
}

int main() {
    cin >> r >> c ;
    vector<int> nul(c,0) ;
    vector<pair<int,int>> null ;
    vector<vector<int>> grid(r,nul);
    map<pair<int,int>,vector<pair<int,int>>> path ;
    vector<int> visit((r*c),-1) ;
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            path[{i,j}] = null ;
        }
    }
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            cin >> grid[i][j] ;
            create_path(i,j,grid[i][j],path);
        }
    }
    int ans = INT_MIN ;
    int component = 0 ;
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            int count = 0 ;
            bool found = false ;
            if (!check_visit(visit,{i,j})) {
                component++;
                dfs(count,component,path,visit,{i,j},make_pair(-1,-1));
                ans = max(count,ans);
            }
        } 
    }
    if (cycle_detect == 0){
        cout << 0 ;
    } else {
        cout << cycle_detect << " " << ans;
    }
}