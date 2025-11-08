function shortestTime(n, edges, src) {
  const graph = Array.from({ length: n }, () => []);
  for (const [u, v] of edges) {
    graph[u].push(v);
    graph[v].push(u);
  }
  const dist = Array(n).fill(-1);
  dist[src] = 0;
  const q = [src];

  while (q.length) {
    const u = q.shift();
    for (const v of graph[u]) {
      if (dist[v] === -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return dist;
}
