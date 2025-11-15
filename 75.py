def longest_consecutive(nums):
    num_set = set(nums)
    longest = 0

    for n in nums:
        if n - 1 not in num_set:  # start of sequence
            length = 1
            cur = n
            while cur + 1 in num_set:
                cur += 1
                length += 1
            longest = max(longest, length)
    
    return longest
