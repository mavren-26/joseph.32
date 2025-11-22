function permute(nums) {
    const res = [];
    const used = new Array(nums.length).fill(false);

    function backtrack(path) {
        if (path.length === nums.length) {
            res.push([...path]);
            return;
        }

        for (let i = 0; i < nums.length; i++) {
            if (used[i]) continue;

            used[i] = true;
            path.push(nums[i]);
            backtrack(path);

            path.pop();
            used[i] = false;
        }
    }

    backtrack([]);
    return res;
}

console.log(permute([1, 2, 3]));
