def minPlatforms(arr, dep):
    arr.sort()
    dep.sort()
    
    i = j = 0
    current = result = 0
    n = len(arr)
    
    while i < n and j < n:
        if arr[i] <= dep[j]:
            current += 1
            result = max(result, current)
            i += 1
        else:
            current -= 1
            j += 1
    return result

# Driver
arr = [900,940,950,1100,1500,1800]
dep = [910,1200,1120,1130,1900,2000]
print("Minimum Platforms:", minPlatforms(arr, dep))
