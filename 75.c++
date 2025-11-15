#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;

    for (int n : nums) {
        if (!s.count(n - 1)) { // start of sequence
            int cur = n, len = 1;
            while (s.count(cur + 1)) {
                cur++;
                len++;
            }
            longest = max(longest, len);
        }
    }
    return longest;
}
