function lengthOfLongestSubstring(s) {
    const lastIndex = new Map(); // char -> last seen index
    let left = 0;
    let maxLen = 0;

    for (let right = 0; right < s.length; right++) {
        const ch = s[right];
        if (lastIndex.has(ch) && lastIndex.get(ch) >= left) {
            left = lastIndex.get(ch) + 1;
        }
        lastIndex.set(ch, right);
        maxLen = Math.max(maxLen, right - left + 1);
    }

    return maxLen;
}
