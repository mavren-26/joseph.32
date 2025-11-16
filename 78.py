def nextGreater(nums):
    n = len(nums)
    res = [-1] * n
    stack = []  # stores indexes

    for i in range(n):
        while stack and nums[i] > nums[stack[-1]]:
            idx = stack.pop()
            res[idx] = nums[i]
        stack.append(i)

    return res

# Driver
print(nextGreater([2,1,2,4,3]))
