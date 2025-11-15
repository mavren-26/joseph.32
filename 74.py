def length_of_longest_substring(s: str) -> int:
    last_index = {}  # char -> last seen index
    left = 0
    max_len = 0

    for right, ch in enumerate(s):
        if ch in last_index and last_index[ch] >= left:
            # Move left just after the previous occurrence
            left = last_index[ch] + 1
        last_index[ch] = right
        max_len = max(max_len, right - left + 1)

    return max_len
