def backtrack(nums, path, used, res):
    if len(path) == len(nums):
        res.append(path[:])
        return

    for i in range(len(nums)):
        if used[i]:
            continue
        used[i] = True
        path.append(nums[i])
        backtrack(nums, path, used, res)
        path.pop()
        used[i] = False

nums = [1, 2]
res = []
used = [False] * len(nums)

backtrack(nums, [], used, res)
for r in res:
    print(r)
