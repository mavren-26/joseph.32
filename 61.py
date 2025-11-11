def maxProduct(nums):
    maxProd = currMax = currMin = nums[0]
    for num in nums[1:]:
        if num < 0:
            currMax, currMin = currMin, currMax
        currMax = max(num, currMax * num)
        currMin = min(num, currMin * num)
        maxProd = max(maxProd, currMax)
    return maxProd

# Driver code
print(maxProduct([2, 3, -2, 4]))  # Output: 6
