# top_k_frequent.py
from collections import Counter
import heapq

def top_k_frequent(nums, k):
    freq = Counter(nums)
    # min-heap of (frequency, number)
    heap = []
    for num, f in freq.items():
        heapq.heappush(heap, (f, num))
        if len(heap) > k:
            heapq.heappop(heap)
    # extract numbers
    return [num for f, num in heap]

# Driver / tests
if __name__ == "__main__":
    tests = [
        ([1,1,1,2,2,3], 2, set([1,2])),
        ([1], 1, set([1])),
        ([4,4,4,6,6,7,7,7,7], 1, set([7])),
    ]
    for nums, k, expected_set in tests:
        out = top_k_frequent(nums, k)
        print("nums:", nums, "k:", k, "->", out)
        assert set(out) == expected_set
    print("Python tests passed.")
