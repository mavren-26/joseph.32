function maxProduct(nums) {
    let maxProd = nums[0];
    let currMax = nums[0];
    let currMin = nums[0];
    
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] < 0) [currMax, currMin] = [currMin, currMax];
        currMax = Math.max(nums[i], currMax * nums[i]);
        currMin = Math.min(nums[i], currMin * nums[i]);
        maxProd = Math.max(maxProd, currMax);
    }
    return maxProd;
}

// Driver code
console.log(maxProduct([2,3,-2,4])); // Output: 6
