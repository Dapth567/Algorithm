#include <bits/stdc++.h>

using namespace std ;

int main () {
    int student , subtask ;
    cin >> student >> subtask ;
    vector<float> task_list(subtask);
    float avg,time ;
    for (size_t i = 0; i < subtask; i++)
    {
        cin >> task_list[i];
    }
    sort(task_list.begin(),task_list.end());

    priority_queue<float> task_handler ;
    for (size_t i = 0; i < student; i++)
    {
        task_handler.push((float)0);
    }
    
    for (size_t i = 0; i < subtask; i++)
    {
        time = -task_handler.top() + task_list[i];
        avg += time ;
        task_handler.push(-time);
        task_handler.pop();
    }
    cout << fixed << setprecision(3);
    cout << avg/subtask ;
    
}