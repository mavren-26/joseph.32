#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < n; i++) graph[arr[i]].push_back(i);
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<int> vis(n,0); vis[0]=1;
    while(!q.empty()){
        auto [i,d]=q.front();q.pop();
        if(i==n-1) return d;
        vector<int> next = graph[arr[i]];
        next.push_back(i-1); next.push_back(i+1);
        for(int j: next){
            if(j>=0 && j<n && !vis[j]){
                vis[j]=1;
                q.push({j,d+1});
            }
        }
        graph[arr[i]].clear();
    }
    return -1;
}
