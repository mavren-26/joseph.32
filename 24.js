function longestWPI(hours) {
  let score = 0;
  const seen = new Map();
  let res = 0;

  for (let i = 0; i < hours.length; i++) {
    score += hours[i] > 8 ? 1 : -1;

    if (score > 0) {
      res = i + 1;
    } else {
      if (seen.has(score - 1)) {
        res = Math.max(res, i - seen.get(score - 1));
      }
    }

    if (!seen.has(score)) {
      seen.set(score, i);
    }
  }

  return res;
}

// Example
console.log(longestWPI([9, 9, 6, 0, 6, 6, 9])); // Output: 3
