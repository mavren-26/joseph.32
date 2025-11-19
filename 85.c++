#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

int activity_selection(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int,int>> activities;
    for(int i = 0; i < n; i++) activities.push_back({start[i], end[i]});
    sort(activities.begin(), activities.end(), [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    });
    int count = 0, last_end = -1;
    for(auto [s,e] : activities){
        if(s >= last_end){
            count++;
            last_end = e;
        }
    }
    return count;
}

int main() {
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};
    cout << "Maximum activities: " << activity_selection(start, end) << endl;
    return 0;
}
