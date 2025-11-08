from collections import deque, defaultdict
def minJumps(arr):
    n = len(arr)
    graph = defaultdict(list)
    for i, val in enumerate(arr):
        graph[val].append(i)
    q = deque([(0,0)])
    visited = set([0])
    while q:
        i, d = q.popleft()
        if i == n-1:
            return d
        for j in [i-1, i+1] + graph[arr[i]]:
            if 0 <= j < n and j not in visited:
                visited.add(j)
                q.append((j, d+1))
        graph[arr[i]].clear()
