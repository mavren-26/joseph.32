def combinationSum(candidates, target):
    res = []

    def backtrack(i, path, total):
        if total == target:
            res.append(path[:])
            return
        if total > target or i == len(candidates):
            return

        # Pick the number
        path.append(candidates[i])
        backtrack(i, path, total + candidates[i])
        path.pop()

        # Skip the number
        backtrack(i + 1, path, total)

    backtrack(0, [], 0)
    return res

print(combinationSum([2,3,6,7], 7))
