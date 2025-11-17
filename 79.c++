// top_k_frequent.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;

    // Count frequencies
    for (int x : nums) {
        freq[x]++;
    }

    // min-heap of pairs (frequency, value)
    using pii = pair<int,int>;
    auto cmp = [](const pii &a, const pii &b){
        return a.first > b.first; 
    };

    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

    // Push to heap
    for (auto &p : freq) {
        pq.emplace(p.second, p.first);
        if (pq.size() > (size_t)k)
            pq.pop();
    }

    // extract answer
    vector<int> res;
    while (!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}

int main() {
    vector<pair<vector<int>, int>> tests = {
        {{1,1,1,2,2,3}, 2},
        {{1}, 1},
        {{4,4,4,6,6,7,7,7,7}, 1}
    };

    for (auto &t : tests) {
        vector<int> nums = t.first;
        int k = t.second;
        vector<int> out = topKFrequent(nums, k);

        cout << "nums: ";
        for (int x : nums) cout << x << " ";
        cout << "  k: " << k << " -> [ ";

        for (int x : out) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
