def count_set_bits(n):
    count = 0
    i = 1

    while i <= n:
        total_pairs = n // (i * 2)
        count += total_pairs * i
        count += max(0, (n % (2 * i)) - i + 1)
        i <<= 1

    return count

print(count_set_bits(5))  # 7
