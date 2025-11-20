#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used, vector<vector<int>>& res) {
    if (curr.size() == nums.size()) {
        res.push_back(curr);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, curr, used, res);
            curr.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> curr;
    vector<bool> used(nums.size(), false);
    backtrack(nums, curr, used, res);
    return res;
}

int main() {
    vector<int> nums = {1, 2};
    vector<vector<int>> ans = permute(nums);

    for (auto &v : ans) {
        cout << "[ ";
        for (auto &x : v) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}
