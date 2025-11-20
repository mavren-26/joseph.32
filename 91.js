function singleNumber(nums) {
    let result = 0;
    for (let x of nums) result ^= x;
    return result;
}

console.log(singleNumber([4,1,2,1,2]));
