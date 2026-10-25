#include <bits/stdc++.h>

using namespace std ;

void generate_num(set<int>lock_member , map<int,vector<int>> unlock_pair , string num ,set<int> possible_num){
    for (auto it = possible_num.begin(); it != possible_num.end(); it++){
        int value = *it;
        set<int> copy_lock_member = lock_member ;
        set<int> copy_pos_num = possible_num ;

        if (lock_member.find(value) == lock_member.end()){   //ตัวที่ลองไม่ถูกห้าม

            copy_pos_num.erase(value) ;
            if (unlock_pair.find(value) != unlock_pair.end()){
                for (size_t i = 0; i < unlock_pair[value].size(); i++)
                {
                    copy_lock_member.erase(unlock_pair[value][i]);
                }
            }
            generate_num(copy_lock_member ,unlock_pair ,num + to_string(value) + " " ,copy_pos_num);
        }
    }
    if (possible_num.size() == 0){
        cout << num << endl ;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n , m , unlock ,lock;
    cin >> n >> m ;
    set<int> lock_member ;
    map<int,vector<int>> unlock_pair ;
    set<int> possible_num ;
    for (size_t i = 0; i < m; i++)
    {
        cin >> unlock >> lock ;
        unlock_pair[unlock].push_back(lock) ;
        lock_member.insert(lock) ;
    }
    for (size_t i = 0; i < n; i++)
    {
        possible_num.insert(i);
    }
    generate_num(lock_member,unlock_pair,"",possible_num);
}