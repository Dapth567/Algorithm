#include <bits/stdc++.h>

using namespace std ;

int dc(vector<vector<int>>& tile,int d,int start_c, int stop_c,int start_r ,int stop_r, bool& FoundError){
    if (d == 1){
        int half_zone = tile.size() / 2 ;
        if (start_c >= half_zone && start_r >= half_zone){
            if (tile[start_c][start_r] != 0){
                FoundError = true ;
                return 0 ;
            } else {
                return tile[start_c][start_r] ;
            }
        } else {
            return tile[start_c][start_r] ;
        }
    }
    int top_left , top_right , bottom_left , bottom_right ;
    top_left = dc(tile,d/2,start_c,(start_c+stop_c)/2,start_r,(start_r+stop_r)/2,FoundError);
    top_right = dc(tile,d/2,start_c,(start_c+stop_c)/2,((start_r+stop_r)/2)+1,stop_r,FoundError);
    bottom_left = dc(tile,d/2,((start_c+stop_c)/2)+1,stop_c,start_r,(start_r+stop_r)/2,FoundError);
    bottom_right = dc(tile,d/2,((start_c+stop_c)/2)+1,stop_c,((start_r+stop_r)/2)+1,stop_r,FoundError);

    if (bottom_right == 0){
        map<int,int> m ;
        m[0] = 0; m[1] = 0 ; m[2] = 0 ; m[3] = 0 ;
        m[bottom_left] += 1 ;
        m[top_left] += 1 ;
        m[top_right] += 1 ;
        if (m[0] > 0){
            return 0 ;
        }
        auto it = m.begin() ;
        it++;
        for (auto it_num = it; it_num != m.end(); it_num++)
        {
            if (it_num->second >= 2){
                return it_num->first ;
            } 
        }
        return 0 ;
    } else {
        FoundError = true ;
        return 0 ;
    }
}

int main() {
    int ans ;
    int c = 3 ,value ;
    while (c--)
    {
        bool FoundError = false ;
        int d ;
        cin >> d ;
        vector<vector<int>> tile ;
        for (size_t i = 0; i < d; i++){
            vector<int> row ;
            for (size_t i = 0; i < d; i++)
            {
                cin >> value ;
                row.push_back(value);
            }
            tile.push_back(row);
        }
        ans = (dc(tile,d,0,d-1,0,d-1,FoundError)) ;
        if (FoundError){
            cout << 0 << endl;
        } else {
            cout << ans << endl;
        }
    }
}