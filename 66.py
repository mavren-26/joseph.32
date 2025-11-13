class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def averageOfSubtree(root):
    count = 0
    def dfs(node):
        nonlocal count
        if not node:
            return (0, 0)
        s1, n1 = dfs(node.left)
        s2, n2 = dfs(node.right)
        total_sum = s1 + s2 + node.val
        total_nodes = n1 + n2 + 1
        if node.val == total_sum // total_nodes:
            count += 1
        return (total_sum, total_nodes)
    dfs(root)
    return count
