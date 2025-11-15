#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> lastIndex; // char -> last seen index
    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < (int)s.size(); ++right) {
        char ch = s[right];
        if (lastIndex.count(ch) && lastIndex[ch] >= left) {
            left = lastIndex[ch] + 1;
        }
        lastIndex[ch] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
