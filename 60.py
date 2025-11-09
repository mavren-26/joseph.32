from collections import defaultdict, deque

def minTime(n, deps):
    # Step 1: Build graph and in-degree array
    graph = defaultdict(list)
    indegree = [0] * (n + 1)
    
    for u, v in deps:
        graph[u].append(v)
        indegree[v] += 1

    # Step 2: Initialize queue with tasks having no dependencies
    q = deque()
    time = [1] * (n + 1)   # each task takes 1 unit of time
    
    for i in range(1, n + 1):
        if indegree[i] == 0:
            q.append(i)

    # Step 3: Topological sort + DP for completion time
    while q:
        curr = q.popleft()
        for nxt in graph[curr]:
            indegree[nxt] -= 1
            # Update time for the dependent task
            time[nxt] = max(time[nxt], time[curr] + 1)
            if indegree[nxt] == 0:
                q.append(nxt)

    # Step 4: Answer = maximum completion time
    return max(time[1:])

# Example 1
print(minTime(3, [[1, 3], [2, 3]]))   # Output: 2

# Example 2
print(minTime(5, [[1, 2], [1, 3], [3, 4], [2, 5], [4, 5]]))   # Output: 4
