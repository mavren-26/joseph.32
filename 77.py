from collections import deque

def maxSlidingWindow(nums, k):
    dq = deque()  # stores indexes
    result = []

    for i in range(len(nums)):
        # remove elements out of window
        if dq and dq[0] <= i - k:
            dq.popleft()

        # maintain monotonic decreasing queue
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()

        dq.append(i)

        # window forms
        if i >= k - 1:
            result.append(nums[dq[0]])

    return result


# Driver
nums = [1,3,-1,-3,5,3,6,7]
k = 3
print(maxSlidingWindow(nums, k))
