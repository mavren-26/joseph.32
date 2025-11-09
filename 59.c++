#include <bits/stdc++.h>
using namespace std;

string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> indegree;
    
    // Initialize indegree for all characters
    for (auto& w : words)
        for (char c : w)
            indegree[c] = 0;

    // Build graph
    for (int i = 0; i < words.size() - 1; i++) {
        string w1 = words[i], w2 = words[i + 1];
        if (w1.size() > w2.size() && w1.find(w2) == 0)
            return ""; // invalid (prefix issue)
        for (int j = 0; j < min(w1.size(), w2.size()); j++) {
            if (w1[j] != w2[j]) {
                if (!graph[w1[j]].count(w2[j])) {
                    graph[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                break;
            }
        }
    }

    // Kahn’s BFS
    queue<char> q;
    for (auto [ch, deg] : indegree)
        if (deg == 0) q.push(ch);

    string result;
    while (!q.empty()) {
        char c = q.front(); q.pop();
        result += c;
        for (char nei : graph[c]) {
            if (--indegree[nei] == 0)
                q.push(nei);
        }
    }

    return result.size() == indegree.size() ? result : "";
}

int main() {
    vector<string> words = {"wrt","wrf","er","ett","rftt"};
    cout << alienOrder(words) << endl;
}
