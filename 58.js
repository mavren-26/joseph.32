function findOrder(numCourses, prerequisites) {
  const graph = Array.from({ length: numCourses }, () => []);
  const indeg = Array(numCourses).fill(0);

  for (const [a, b] of prerequisites) {
    graph[b].push(a);
    indeg[a]++;
  }

  const queue = [];
  for (let i = 0; i < numCourses; i++)
    if (indeg[i] === 0) queue.push(i);

  const order = [];
  while (queue.length) {
    const node = queue.shift();
    order.push(node);
    for (const nei of graph[node]) {
      indeg[nei]--;
      if (indeg[nei] === 0) queue.push(nei);
    }
  }
  return order.length === numCourses ? order : [];
}
