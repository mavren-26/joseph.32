# task_scheduler.py
import heapq
from collections import Counter, deque

def least_interval(tasks, n):
    if n == 0:
        return len(tasks)
    freq = Counter(tasks)
    # max-heap using negative counts
    heap = [-c for c in freq.values()]
    heapq.heapify(heap)
    time = 0
    while heap:
        temp = []
        k = n + 1
        for _ in range(k):
            if heap:
                c = heapq.heappop(heap)
                if c + 1 < 0:  # still tasks remaining
                    temp.append(c+1)
                time += 1
            else:
                # if nothing to do but there are pending tasks in temp, we count idle
                if temp:
                    time += 1
                else:
                    break
        for item in temp:
            heapq.heappush(heap, item)
    return time

# Driver
if __name__ == "__main__":
    tests = [
        (["A","A","A","B","B","B"], 2, 8),
        (["A","A","A","B","B","B"], 0, 6),
        (["A","A","A","A","A","A","B","C","D","E","F","G"], 2, 16)
    ]
    for tasks, n, expected in tests:
        out = least_interval(tasks, n)
        print("tasks:", tasks, "n:", n, "->", out, " expected:", expected)
        assert out == expected
    print("Python Task Scheduler tests passed.")
