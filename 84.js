function backtrack(nums, path, used, res) {
    if (path.length === nums.length) {
        res.push([...path]);
        return;
    }

    for (let i = 0; i < nums.length; i++) {
        if (used[i]) continue;

        used[i] = true;
        path.push(nums[i]);
        backtrack(nums, path, used, res);
        path.pop();
        used[i] = false;
    }
}

const nums = [1, 2];
const used = Array(nums.length).fill(false);
const res = [];

backtrack(nums, [], used, res);
console.log(res);
