function shortestPath(grid) {
  const n = grid.length, m = grid[0].length;
  if (grid[0][0] === 1) return -1;
  const q = [[0, 0, 0]];
  const visited = new Set(["0,0"]);

  const dirs = [[1,0],[-1,0],[0,1],[0,-1]];
  while (q.length) {
    const [x, y, d] = q.shift();
    if (x === n - 1 && y === m - 1) return d;
    for (const [dx, dy] of dirs) {
      const nx = x + dx, ny = y + dy;
      const key = `${nx},${ny}`;
      if (nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]===0 && !visited.has(key)) {
        visited.add(key);
        q.push([nx, ny, d + 1]);
      }
    }
  }
  return -1;
}
