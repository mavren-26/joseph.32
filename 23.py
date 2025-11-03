def maxSubarraySumCircular(nums):
    total_sum = sum(nums)
    
    # Kadane’s for max subarray sum (non-circular)
    cur_max = max_sum = nums[0]
    # Kadane’s for min subarray sum
    cur_min = min_sum = nums[0]
    
    for n in nums[1:]:
        cur_max = max(n, cur_max + n)
        max_sum = max(max_sum, cur_max)

        cur_min = min(n, cur_min + n)
        min_sum = min(min_sum, cur_min)
    
    # Case 1: non-circular max_sum
    # Case 2: circular -> total_sum - min_sum
    if max_sum < 0:
        return max_sum  # All numbers are negative
    return max(max_sum, total_sum - min_sum)


# Example
print(maxSubarraySumCircular([1, -2, 3, -2]))  # Output: 3
