function combinationSum(candidates, target) {
    const res = [];

    function backtrack(i, path, total) {
        if (total === target) {
            res.push([...path]);
            return;
        }
        if (total > target || i === candidates.length) return;

        // pick
        path.push(candidates[i]);
        backtrack(i, path, total + candidates[i]);
        path.pop();

        // skip
        backtrack(i + 1, path, total);
    }

    backtrack(0, [], 0);
    return res;
}

console.log(combinationSum([2, 3, 6, 7], 7));
