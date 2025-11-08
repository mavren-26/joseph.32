#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    if (grid[0][0] == 1) return -1;
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    vector<vector<int>> vis(n, vector<int>(m,0));
    vis[0][0] = 1;
    
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.empty()) {
        auto [x,y,d] = q.front(); q.pop();
        if (x==n-1 && y==m-1) return d;
        for (auto &dir: dirs) {
            int nx=x+dir[0], ny=y+dir[1];
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&!vis[nx][ny]&&grid[nx][ny]==0){
                vis[nx][ny]=1;
                q.push({nx,ny,d+1});
            }
        }
    }
    return -1;
}
