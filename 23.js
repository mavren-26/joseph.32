function maxSubarraySumCircular(nums) {
  const total = nums.reduce((a, b) => a + b, 0);

  let curMax = nums[0], maxSum = nums[0];
  let curMin = nums[0], minSum = nums[0];

  for (let i = 1; i < nums.length; i++) {
    curMax = Math.max(nums[i], curMax + nums[i]);
    maxSum = Math.max(maxSum, curMax);

    curMin = Math.min(nums[i], curMin + nums[i]);
    minSum = Math.min(minSum, curMin);
  }

  // If all are negative, return the maximum single element
  if (maxSum < 0) return maxSum;
  
  return Math.max(maxSum, total - minSum);
}

// Example
console.log(maxSubarraySumCircular([1, -2, 3, -2])); // Output: 3
