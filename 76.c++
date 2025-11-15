#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestSubarrayAtMostKDistinct(const vector<int>& nums, int k) {
    unordered_map<int, int> freq; // value -> count in window
    int left = 0;
    int distinct = 0;
    int maxLen = 0;

    for (int right = 0; right < (int)nums.size(); ++right) {
        int val = nums[right];
        if (freq[val] == 0) {
            distinct++;
        }
        freq[val]++;

        while (distinct > k) {
            int leftVal = nums[left];
            freq[leftVal]--;
            if (freq[leftVal] == 0) {
                distinct--;
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
