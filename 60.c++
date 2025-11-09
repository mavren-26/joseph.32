#include <bits/stdc++.h>
using namespace std;

int minTime(int n, vector<vector<int>>& deps) {
    vector<vector<int>> graph(n + 1);
    vector<int> indeg(n + 1, 0);
    vector<int> time(n + 1, 1); // each task takes 1 unit

    // Build graph
    for (auto& d : deps) {
        int u = d[0], v = d[1];
        graph[u].push_back(v);
        indeg[v]++;
    }

    // Queue for Kahn’s BFS
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
            q.push(i);

    // Topological + DP
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int nxt : graph[curr]) {
            indeg[nxt]--;
            time[nxt] = max(time[nxt], time[curr] + 1);
            if (indeg[nxt] == 0)
                q.push(nxt);
        }
    }

    return *max_element(time.begin() + 1, time.end());
}

// -------------------- DRIVER CODE --------------------
int main() {
    int n = 5;
    vector<vector<int>> deps = {{1, 2}, {1, 3}, {3, 4}, {2, 5}, {4, 5}};
    cout << "Minimum Time: " << minTime(n, deps) << endl; // Output: 4

    vector<vector<int>> deps2 = {{1, 3}, {2, 3}};
    cout << "Minimum Time: " << minTime(3, deps2) << endl; // Output: 2
}
