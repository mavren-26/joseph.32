import heapq

pq = []
arrival = 0

n = int(input())
for _ in range(n):
    parts = input().split()
    cmd = parts[0]

    if cmd == "ADD":
        name = parts[1]
        severity = int(parts[2])
        heapq.heappush(pq, (-severity, arrival, name))
        arrival += 1

    elif cmd == "TREAT":
        if not pq:
            print("EMPTY")
        else:
            _, _, name = heapq.heappop(pq)
            print(name)

    elif cmd == "PEEK":
        if not pq:
            print("EMPTY")
        else:
            print(pq[0][2])

    elif cmd == "SIZE":
        print(len(pq))
