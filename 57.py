from collections import deque

def canFinish(numCourses, prerequisites):
    graph = [[] for _ in range(numCourses)]
    indeg = [0] * numCourses
    for a, b in prerequisites:
        graph[b].append(a)
        indeg[a] += 1

    q = deque([i for i in range(numCourses) if indeg[i] == 0])
    count = 0
    while q:
        node = q.popleft()
        count += 1
        for nei in graph[node]:
            indeg[nei] -= 1
            if indeg[nei] == 0:
                q.append(nei)
    return count == numCourses
