#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int curMax = nums[0], maxSum = nums[0];
    int curMin = nums[0], minSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        curMax = max(nums[i], curMax + nums[i]);
        maxSum = max(maxSum, curMax);

        curMin = min(nums[i], curMin + nums[i]);
        minSum = min(minSum, curMin);
    }

    if (maxSum < 0) return maxSum; // all negatives
    return max(maxSum, total - minSum);
}

int main() {
    vector<int> nums = {1, -2, 3, -2};
    cout << maxSubarraySumCircular(nums) << endl;  // Output: 3
    return 0;
}
