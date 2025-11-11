function longestConsecutive(nums) {
    const set = new Set(nums);
    let longest = 0;
    for (const num of set) {
        if (!set.has(num - 1)) {
            let current = num, streak = 1;
            while (set.has(current + 1)) {
                current++;
                streak++;
            }
            longest = Math.max(longest, streak);
        }
    }
    return longest;
}

// Driver
console.log(longestConsecutive([100,4,200,1,3,2]));
