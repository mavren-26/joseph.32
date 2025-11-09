function alienOrder(words) {
  const graph = new Map();
  const indegree = new Map();

  // Initialize all characters
  for (const w of words)
    for (const c of w) indegree.set(c, 0);

  // Build graph
  for (let i = 0; i < words.length - 1; i++) {
    const w1 = words[i], w2 = words[i + 1];
    if (w1.length > w2.length && w1.startsWith(w2)) return "";

    for (let j = 0; j < Math.min(w1.length, w2.length); j++) {
      if (w1[j] !== w2[j]) {
        if (!graph.has(w1[j])) graph.set(w1[j], new Set());
        if (!graph.get(w1[j]).has(w2[j])) {
          graph.get(w1[j]).add(w2[j]);
          indegree.set(w2[j], indegree.get(w2[j]) + 1);
        }
        break;
      }
    }
  }

  // Kahn’s BFS
  const queue = [];
  for (const [ch, deg] of indegree)
    if (deg === 0) queue.push(ch);

  const result = [];
  while (queue.length) {
    const c = queue.shift();
    result.push(c);
    if (graph.has(c)) {
      for (const nei of graph.get(c)) {
        indegree.set(nei, indegree.get(nei) - 1);
        if (indegree.get(nei) === 0) queue.push(nei);
      }
    }
  }

  return result.length === indegree.size ? result.join('') : "";
}
