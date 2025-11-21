function findTwoUnique(nums) {
    let xor = 0;

    for (let n of nums) xor ^= n;

    // Rightmost set bit
    let rightBit = xor & -xor;

    let a = 0, b = 0;

    for (let n of nums) {
        if (n & rightBit) a ^= n;
        else b ^= n;
    }

    return [a, b];
}

// Test
console.log(findTwoUnique([4, 1, 2, 1, 2, 5]));
