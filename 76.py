def longest_subarray_at_most_k_distinct(nums, k):
    from collections import defaultdict

    freq = defaultdict(int)
    left = 0
    distinct = 0
    max_len = 0

    for right, val in enumerate(nums):
        if freq[val] == 0:
            distinct += 1
        freq[val] += 1

        while distinct > k:
            left_val = nums[left]
            freq[left_val] -= 1
            if freq[left_val] == 0:
                distinct -= 1
            left += 1

        max_len = max(max_len, right - left + 1)

    return max_len
