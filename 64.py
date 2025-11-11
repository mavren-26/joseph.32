def subarraySum(nums, k):
    prefix = {0: 1}
    count = 0
    total = 0
    for num in nums:
        total += num
        if total - k in prefix:
            count += prefix[total - k]
        prefix[total] = prefix.get(total, 0) + 1
    return count

# Driver
print(subarraySum([1,1,1], 2))  # Output: 2
