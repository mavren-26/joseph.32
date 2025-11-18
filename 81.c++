#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Patient {
    string name;
    int severity;
    int order;
};

struct Compare {
    bool operator()(const Patient &a, const Patient &b) {
        if (a.severity == b.severity)
            return a.order > b.order;      // earlier patient first
        return a.severity < b.severity;    // higher severity first
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<Patient, vector<Patient>, Compare> pq;
    int N;
    cin >> N;

    int arrival = 0;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "ADD") {
            string name;
            int sev;
            cin >> name >> sev;
            pq.push({name, sev, arrival++});
        }
        else if (cmd == "TREAT") {
            if (pq.empty()) {
                cout << "EMPTY\n";
            } else {
                cout << pq.top().name << "\n";
                pq.pop();
            }
        }
        else if (cmd == "PEEK") {
            if (pq.empty()) {
                cout << "EMPTY\n";
            } else {
                cout << pq.top().name << "\n";
            }
        }
        else if (cmd == "SIZE") {
            cout << pq.size() << "\n";
        }
    }

    return 0;
}
