#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Job {
    string id;
    int time;
    int priority;
};

struct Compare {
    bool operator()(const Job &a, const Job &b) {
        if (a.priority == b.priority) {
            if (a.time == b.time)
                return a.id > b.id;     // lexicographically larger goes later
            return a.time > b.time;      // smaller time first
        }
        return a.priority < b.priority;  // higher priority first
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<Job, vector<Job>, Compare> pq;
    int Q;
    cin >> Q;

    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "ADD") {
            string id;
            int t, p;
            cin >> id >> t >> p;
            pq.push({id, t, p});
        }
        else if (cmd == "RUN") {
            if (pq.empty()) {
                cout << "EMPTY\n";
            } else {
                cout << pq.top().id << "\n";
                pq.pop();
            }
        }
        else if (cmd == "TOP") {
            if (pq.empty()) {
                cout << "EMPTY\n";
            } else {
                cout << pq.top().id << "\n";
            }
        }
        else if (cmd == "COUNT") {
            cout << pq.size() << "\n";
        }
    }
    return 0;
}
