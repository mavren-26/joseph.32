#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void backtrack(vector<int> &nums, int i, vector<int> &temp) {
    if (i == nums.size()) {
        ans.push_back(temp);
        return;
    }
    // not take
    backtrack(nums, i + 1, temp);

    // take
    temp.push_back(nums[i]);
    backtrack(nums, i + 1, temp);
    temp.pop_back();
}

int main() {
    vector<int> nums = {1, 2};
    vector<int> temp;
    backtrack(nums, 0, temp);

    for (auto &v : ans) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i + 1 < v.size()) cout << ",";
        }
        cout << "]\n";
    }
}
