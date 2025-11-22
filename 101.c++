#include <iostream>
#include <vector>
using namespace std;

void backtrack(int i, vector<int>& nums, int target, vector<int>& path, vector<vector<int>>& res, int total) {
    if (total == target) {
        res.push_back(path);
        return;
    }
    if (total > target || i == nums.size())
        return;

    // pick
    path.push_back(nums[i]);
    backtrack(i, nums, target, path, res, total + nums[i]);
    path.pop_back();

    // skip
    backtrack(i + 1, nums, target, path, res, total);
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    vector<int> path;
    backtrack(0, nums, target, path, res, 0);
    return res;
}

int main() {
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;

    auto ans = combinationSum(nums, target);
    for (auto &v : ans) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }
}
