function canFinish(numCourses, prerequisites) {
  const graph = Array.from({ length: numCourses }, () => []);
  const indeg = Array(numCourses).fill(0);

  for (const [a, b] of prerequisites) {
    graph[b].push(a);
    indeg[a]++;
  }

  const queue = [];
  for (let i = 0; i < numCourses; i++)
    if (indeg[i] === 0) queue.push(i);

  let count = 0;
  while (queue.length) {
    const node = queue.shift();
    count++;
    for (const nei of graph[node]) {
      indeg[nei]--;
      if (indeg[nei] === 0) queue.push(nei);
    }
  }
  return count === numCourses;
}
