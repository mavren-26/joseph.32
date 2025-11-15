function longestSubarrayAtMostKDistinct(nums, k) {
    const freq = new Map();  // value -> count
    let left = 0;
    let distinct = 0;
    let maxLen = 0;

    for (let right = 0; right < nums.length; right++) {
        const val = nums[right];
        if (!freq.has(val) || freq.get(val) === 0) {
            distinct++;
        }
        freq.set(val, (freq.get(val) || 0) + 1);

        while (distinct > k) {
            const leftVal = nums[left];
            freq.set(leftVal, freq.get(leftVal) - 1);
            if (freq.get(leftVal) === 0) {
                distinct--;
            }
            left++;
        }

        maxLen = Math.max(maxLen, right - left + 1);
    }

    return maxLen;
}
