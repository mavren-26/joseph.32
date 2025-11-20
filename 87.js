function minPlatforms(arr, dep) {
    arr.sort((a,b)=>a-b);
    dep.sort((a,b)=>a-b);

    let i = 0, j = 0;
    let current = 0, result = 0;

    while (i < arr.length && j < dep.length) {
        if (arr[i] <= dep[j]) {
            current++;
            result = Math.max(result, current);
            i++;
        } else {
            current--;
            j++;
        }
    }
    return result;
}

// Driver
console.log("Minimum Platforms:",
    minPlatforms([900,940,950,1100,1500,1800],
                 [910,1200,1120,1130,1900,2000])
);
