class MinStack {
    constructor() {
        this.stack = [];
        this.minStack = [];
    }

    push(x) {
        this.stack.push(x);
        if (this.minStack.length === 0)
            this.minStack.push(x);
        else
            this.minStack.push(Math.min(x, this.minStack[this.minStack.length - 1]));
    }

    pop() {
        if (this.stack.length > 0) {
            this.stack.pop();
            this.minStack.pop();
        }
    }

    top() {
        return this.stack[this.stack.length - 1];
    }

    getMin() {
        return this.minStack[this.minStack.length - 1];
    }
}

// Driver Code
let obj = new MinStack();
obj.push(5);
obj.push(2);
obj.push(8);
console.log(obj.getMin()); // 2
obj.pop();
console.log(obj.top());    // 2
console.log(obj.getMin()); // 2
