function backtrack(nums, i, path, res) {
    if (i === nums.length) {
        res.push([...path]);
        return;
    }

    backtrack(nums, i + 1, path, res);
    path.push(nums[i]);
    backtrack(nums, i + 1, path, res);
    path.pop();
}

const nums = [1, 2];
const res = [];
backtrack(nums, 0, [], res);

console.log(res);
