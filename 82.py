import heapq

pq = []

Q = int(input())
for _ in range(Q):
    parts = input().split()
    cmd = parts[0]

    if cmd == "ADD":
        job_id = parts[1]
        t = int(parts[2])
        p = int(parts[3])
        heapq.heappush(pq, (-p, t, job_id))

    elif cmd == "RUN":
        if not pq:
            print("EMPTY")
        else:
            _, _, job_id = heapq.heappop(pq)
            print(job_id)

    elif cmd == "TOP":
        if not pq:
            print("EMPTY")
        else:
            print(pq[0][2])

    elif cmd == "COUNT":
        print(len(pq))
