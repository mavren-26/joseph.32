function averageOfSubtree(root) {
    let count = 0;
    function dfs(node) {
        if (!node) return [0, 0];
        const [s1, n1] = dfs(node.left);
        const [s2, n2] = dfs(node.right);
        const total = s1 + s2 + node.val;
        const num = n1 + n2 + 1;
        if (Math.floor(total / num) === node.val) count++;
        return [total, num];
    }
    dfs(root);
    return count;
}
