vector<int> findOrder(int n, vector<vector<int>>& pre) {
    vector<vector<int>> g(n);
    vector<int> indeg(n, 0);
    for (auto& p : pre) {
        g[p[1]].push_back(p[0]);
        indeg[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);
        for (int nei : g[node])
            if (--indeg[nei] == 0) q.push(nei);
    }
    return order.size() == n ? order : vector<int>();
}
