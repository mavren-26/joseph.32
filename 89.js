function subsets(nums) {
    const res = [];
    const subset = [];

    function backtrack(i) {
        if (i === nums.length) {
            res.push([...subset]);
            return;
        }
        subset.push(nums[i]);
        backtrack(i + 1);
        subset.pop();
        backtrack(i + 1);
    }

    backtrack(0);
    return res;
}

console.log(subsets([1,2]));
