#include <iostream>
#include <vector>
using namespace std;

void backtrack(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {
    if (i == nums.size()) {
        res.push_back(subset);
        return;
    }
    subset.push_back(nums[i]);
    backtrack(i + 1, nums, subset, res);
    subset.pop_back();
    backtrack(i + 1, nums, subset, res);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> subset;
    backtrack(0, nums, subset, res);
    return res;
}

int main() {
    vector<int> nums = {1, 2};
    vector<vector<int>> ans = subsets(nums);

    for (auto &v : ans) {
        cout << "[ ";
        for (auto &x : v) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}
