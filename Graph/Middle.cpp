#include <bits/stdc++.h>

using namespace std ;

int main() {
    int v ,to ,way;
    cin >> v ;
    unordered_map<int,int> start ;
    map<int,vector<int>> path ;
    for (size_t i = 1; i <= 3; i++)
    {
        cin >> start[i] ;
    }
    for (size_t i = 1; i <= v; i++)
    {
        cin >> way ;
        for (size_t j = 0; j < way; j++)
        {
            cin >> to;
            path[i].push_back(to);
        }
    }
    vector<int> value(v+1,-1);
    vector<vector<int>> each_val(4,value);
    for (size_t i = 1; i <= 3; i++)
    {
        int begin = start[i];
        queue<int> order ;
        order.push(begin);
        each_val[i][begin] = 0 ;
        while (!order.empty())
        {
            int run = order.front();
            for (auto goal : path[run])
            {
                if (each_val[i][goal] == -1){
                    each_val[i][goal] = each_val[i][run] + 1;
                    order.push(goal);
                } else {
                    if (each_val[i][run] + 1 < each_val[i][goal]){
                        each_val[i][goal] = each_val[i][run] + 1 ;
                        order.push(goal);
                    }
                }
            }
            order.pop();
        }
    }
    int max_val = INT_MAX ;
    for (size_t i = 1; i <= v; i++)
    {
        int initial_max = max_val;
        bool brak = false;
        int this_loop_max = INT_MIN ;
        for (size_t j = 1; j <= 3; j++)
        {
            if (each_val[j][i] == -1 ){
                brak = true ;
                break;
            } else {
                this_loop_max = max(each_val[j][i],this_loop_max);
            }
        }
        if (!brak){
            max_val = min(this_loop_max,max_val); 
        }
               
    }
    cout << max_val << "\n";

    for (auto row : each_val)
    {
        for (auto num : row)
        {
            cout << num << " ";
        }
        cout << "\n" ;
    }
    
}