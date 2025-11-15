function longestConsecutive(nums) {
    const setNums = new Set(nums);
    let longest = 0;

    for (const n of nums) {
        if (!setNums.has(n - 1)) {
            let cur = n;
            let len = 1;
            while (setNums.has(cur + 1)) {
                cur++;
                len++;
            }
            longest = Math.max(longest, len);
        }
    }
    return longest;
}
