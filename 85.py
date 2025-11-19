def activity_selection(start, end):
    activities = sorted(zip(start, end), key=lambda x: x[1])
    count = 0
    last_end = -1
    for s, e in activities:
        if s >= last_end:
            count += 1
            last_end = e
    return count

# Driver code
if __name__ == "__main__":
    start = [1, 3, 0, 5, 8, 5]
    end = [2, 4, 6, 7, 9, 9]
    print("Maximum activities:", activity_selection(start, end))
