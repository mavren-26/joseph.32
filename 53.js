function minJumps(arr) {
  const n = arr.length;
  const graph = {};
  arr.forEach((v, i) => (graph[v] ??= []).push(i));
  const q = [[0, 0]];
  const visited = new Set([0]);

  while (q.length) {
    const [i, d] = q.shift();
    if (i === n - 1) return d;
    for (const j of [i - 1, i + 1, ...(graph[arr[i]] || [])]) {
      if (j >= 0 && j < n && !visited.has(j)) {
        visited.add(j);
        q.push([j, d + 1]);
      }
    }
    graph[arr[i]] = [];
  }
  return -1;
}
