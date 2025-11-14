class MinStack:
    def __init__(self):
        self.stack = []
        self.minStack = []

    def push(self, x):
        self.stack.append(x)
        if not self.minStack or x <= self.minStack[-1]:
            self.minStack.append(x)
        else:
            self.minStack.append(self.minStack[-1])

    def pop(self):
        if self.stack:
            self.stack.pop()
            self.minStack.pop()

    def top(self):
        return self.stack[-1] if self.stack else None

    def getMin(self):
        return self.minStack[-1] if self.minStack else None


# Driver code
obj = MinStack()
obj.push(5)
obj.push(2)
obj.push(8)
print(obj.getMin())  # 2
obj.pop()
print(obj.top())     # 2
print(obj.getMin())  # 2
