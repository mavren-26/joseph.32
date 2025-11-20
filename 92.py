def countBits(n):
    count = 0
    while n:
        n &= (n - 1)  # remove last set bit
        count += 1
    return count

print(countBits(11))
