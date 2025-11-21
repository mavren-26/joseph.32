function countSetBits(n) {
    let count = 0;
    let i = 1;

    while (i <= n) {
        let totalPairs = Math.floor(n / (i * 2));
        count += totalPairs * i;
        count += Math.max(0, (n % (2 * i)) - i + 1);
        i <<= 1;
    }
    return count;
}

console.log(countSetBits(5)); // 7
