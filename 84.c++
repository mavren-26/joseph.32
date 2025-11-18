#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void backtrack(vector<int> &nums, vector<int> &temp, vector<bool> &used) {
    if (temp.size() == nums.size()) {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;

        used[i] = true;
        temp.push_back(nums[i]);
        backtrack(nums, temp, used);
        temp.pop_back();
        used[i] = false;
    }
}

int main() {
    vector<int> nums = {1, 2};
    vector<bool> used(nums.size(), false);
    vector<int> temp;

    backtrack(nums, temp, used);

    for (auto &v : ans) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i + 1 < v.size()) cout << ",";
        }
        cout << "]\n";
    }
}
