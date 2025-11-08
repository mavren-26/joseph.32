from collections import deque

def shortestPath(grid):
    n, m = len(grid), len(grid[0])
    if grid[0][0] == 1: return -1
    q = deque([(0, 0, 0)])
    visited = set([(0, 0)])
    
    while q:
        x, y, d = q.popleft()
        if x == n - 1 and y == m - 1:
            return d
        for dx, dy in [(1,0),(-1,0),(0,1),(0,-1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == 0 and (nx, ny) not in visited:
                visited.add((nx, ny))
                q.append((nx, ny, d + 1))
    return -1
