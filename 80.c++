// task_scheduler.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    if (n == 0) return tasks.size();

    vector<int> cnt(26, 0);
    for (char c : tasks) cnt[c - 'A']++;

    priority_queue<int> pq;
    for (int c : cnt) {
        if (c > 0) pq.push(c);
    }

    int time = 0;

    while (!pq.empty()) {
        vector<int> temp;
        int k = n + 1;

        for (int i = 0; i < k; i++) {
            if (!pq.empty()) {
                int top = pq.top();
                pq.pop();
                top--;

                if (top > 0) temp.push_back(top);
                time++;
            } else {
                if (!temp.empty()) {
                    time++;   // idle time
                } else {
                    break;    // no tasks left
                }
            }
        }

        for (int x : temp) pq.push(x);
    }

    return time;
}

int main() {
    vector<pair<vector<char>, int>> tests = {
        {{'A','A','A','B','B','B'}, 2},
        {{'A','A','A','B','B','B'}, 0},
        {{'A','A','A','A','A','A','B','C','D','E','F','G'}, 2}
    };

    vector<int> expect = {8, 6, 16};

    for (int i = 0; i < (int)tests.size(); i++) {
        int out = leastInterval(tests[i].first, tests[i].second);

        cout << "tasks: ";
        for (char c : tests[i].first) cout << c;
        cout << " n:" << tests[i].second 
             << " -> " << out 
             << " expected " << expect[i] << "\n";
    }

    return 0;
}
