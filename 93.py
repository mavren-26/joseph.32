def find_two_unique(nums):
    xor = 0
    for n in nums:
        xor ^= n

    right_bit = xor & -xor

    a, b = 0, 0
    for n in nums:
        if n & right_bit:
            a ^= n
        else:
            b ^= n

    return a, b

print(find_two_unique([4,1,2,1,2,5]))
