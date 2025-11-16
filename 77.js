function maxSlidingWindow(nums, k) {
  const dq = []; // store indexes
  const res = [];

  for (let i = 0; i < nums.length; i++) {
    if (dq.length && dq[0] <= i - k) dq.shift();

    while (dq.length && nums[dq[dq.length - 1]] < nums[i]) {
      dq.pop();
    }

    dq.push(i);

    if (i >= k - 1) res.push(nums[dq[0]]);
  }

  return res;
}

// Driver
console.log(maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3));
