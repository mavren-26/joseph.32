from collections import defaultdict, deque

def alienOrder(words):
    # Step 1: Initialize graph
    graph = defaultdict(set)
    indegree = {c: 0 for w in words for c in w}

    # Step 2: Build graph by comparing adjacent words
    for i in range(len(words) - 1):
        w1, w2 = words[i], words[i + 1]
        # Invalid case: prefix longer but comes before shorter
        if len(w1) > len(w2) and w1.startswith(w2):
            return ""
        for c1, c2 in zip(w1, w2):
            if c1 != c2:
                if c2 not in graph[c1]:
                    graph[c1].add(c2)
                    indegree[c2] += 1
                break

    # Step 3: BFS (Topological Sort)
    q = deque([c for c in indegree if indegree[c] == 0])
    res = []

    while q:
        c = q.popleft()
        res.append(c)
        for nei in graph[c]:
            indegree[nei] -= 1
            if indegree[nei] == 0:
                q.append(nei)

    return "".join(res) if len(res) == len(indegree) else ""
