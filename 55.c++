#include <bits/stdc++.h>
using namespace std;

vector<int> shortestTime(int n, vector<vector<int>>& edges, int src){
    vector<vector<int>> g(n);
    for(auto &e: edges){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    vector<int> dist(n, -1);
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v: g[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist;
}
