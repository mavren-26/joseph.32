#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& pre) {
    vector<vector<int>> g(numCourses);
    vector<int> indeg(numCourses, 0);
    for (auto& p : pre) {
        g[p[1]].push_back(p[0]);
        indeg[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (indeg[i] == 0) q.push(i);

    int count = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        count++;
        for (int nei : g[node])
            if (--indeg[nei] == 0) q.push(nei);
    }
    return count == numCourses;
}
