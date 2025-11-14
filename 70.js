function isValid(s) {
    let stack = [];
    let map = {")": "(", "]": "[", "}": "{"};

    for (let c of s) {
        if (c === "(" || c === "[" || c === "{") {
            stack.push(c);
        } else {
            if (!stack.length || stack[stack.length - 1] !== map[c])
                return false;
            stack.pop();
        }
    }
    return stack.length === 0;
}

// Driver Code
console.log(isValid("()[]{}")); // true
console.log(isValid("(]"));     // false
