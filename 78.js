function nextGreater(nums) {
  const n = nums.length;
  const res = Array(n).fill(-1);
  const st = [];

  for (let i = 0; i < n; i++) {
    while (st.length && nums[i] > nums[st[st.length - 1]]) {
      const idx = st.pop();
      res[idx] = nums[i];
    }
    st.push(i);
  }

  return res;
}

// Driver
console.log(nextGreater([2,1,2,4,3]));
