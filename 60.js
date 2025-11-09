function minTime(n, deps) {
  const graph = Array.from({ length: n + 1 }, () => []);
  const indeg = Array(n + 1).fill(0);
  const time = Array(n + 1).fill(1); // Each task takes 1 unit

  // Build graph
  for (const [u, v] of deps) {
    graph[u].push(v);
    indeg[v]++;
  }

  // Queue for tasks with no dependencies
  const queue = [];
  for (let i = 1; i <= n; i++) {
    if (indeg[i] === 0) queue.push(i);
  }

  // Topological Sort + DP
  while (queue.length) {
    const curr = queue.shift();
    for (const nxt of graph[curr]) {
      indeg[nxt]--;
      time[nxt] = Math.max(time[nxt], time[curr] + 1);
      if (indeg[nxt] === 0) queue.push(nxt);
    }
  }

  return Math.max(...time.slice(1));
}

// -------------------- DRIVER CODE --------------------
const deps1 = [[1, 3], [2, 3]];
console.log("Minimum Time:", minTime(3, deps1)); // Output: 2

const deps2 = [[1, 2], [1, 3], [3, 4], [2, 5], [4, 5]];
console.log("Minimum Time:", minTime(5, deps2)); // Output: 4
