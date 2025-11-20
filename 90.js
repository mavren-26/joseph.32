function permute(nums) {
    const res = [];
    const used = Array(nums.length).fill(false);
    const curr = [];

    function backtrack() {
        if (curr.length === nums.length) {
            res.push([...curr]);
            return;
        }
        for (let i = 0; i < nums.length; i++) {
            if (!used[i]) {
                used[i] = true;
                curr.push(nums[i]);
                backtrack();
                curr.pop();
                used[i] = false;
            }
        }
    }

    backtrack();
    return res;
}

console.log(permute([1,2]));
