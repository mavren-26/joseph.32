from collections import deque
def shortestTime(n, edges, src):
    graph = [[] for _ in range(n)]
    for u,v in edges:
        graph[u].append(v)
        graph[v].append(u)
    dist=[-1]*n
    dist[src]=0
    q=deque([src])
    while q:
        u=q.popleft()
        for v in graph[u]:
            if dist[v]==-1:
                dist[v]=dist[u]+1
                q.append(v)
    return dist
