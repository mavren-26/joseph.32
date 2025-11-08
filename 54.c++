#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<int>>& edges, int src){
    vector<vector<pair<int,int>>> g(n);
    for(auto &e: edges){
        g[e[0]].push_back({e[1], e[2]});
        g[e[1]].push_back({e[0], e[2]});
    }
    vector<int> dist(n, INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [v,w]: g[u]){
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
