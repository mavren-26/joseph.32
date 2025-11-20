def singleNumber(nums):
    result = 0
    for x in nums:
        result ^= x
    return result

print(singleNumber([4,1,2,1,2]))
