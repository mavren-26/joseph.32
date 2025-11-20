def subsets(nums):
    res = []
    subset = []

    def backtrack(i):
        if i == len(nums):
            res.append(subset.copy())
            return
        # include nums[i]
        subset.append(nums[i])
        backtrack(i + 1)
        subset.pop()
        # exclude nums[i]
        backtrack(i + 1)

    backtrack(0)
    return res

print(subsets([1,2]))
