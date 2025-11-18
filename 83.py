def backtrack(nums, i, path, result):
    if i == len(nums):
        result.append(path[:])
        return

    backtrack(nums, i + 1, path, result)
    path.append(nums[i])
    backtrack(nums, i + 1, path, result)
    path.pop()

nums = [1, 2]
result = []
backtrack(nums, 0, [], result)

for r in result:
    print(r)
