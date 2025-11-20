def permute(nums):
    res = []
    used = [False] * len(nums)
    curr = []

    def backtrack():
        if len(curr) == len(nums):
            res.append(curr.copy())
            return
        for i in range(len(nums)):
            if not used[i]:
                used[i] = True
                curr.append(nums[i])
                backtrack()
                curr.pop()
                used[i] = False

    backtrack()
    return res

print(permute([1,2]))
