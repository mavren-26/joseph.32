#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefix;
    prefix[0] = 1;
    int count = 0, sum = 0;
    for (int num : nums) {
        sum += num;
        if (prefix.count(sum - k)) count += prefix[sum - k];
        prefix[sum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {1,1,1};
    int k = 2;
    cout << subarraySum(nums, k); // Output: 2
}
