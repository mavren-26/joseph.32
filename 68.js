function lcaDeepestLeaves(root) {
    function dfs(node) {
        if (!node) return [0, null];
        const [ld, ln] = dfs(node.left);
        const [rd, rn] = dfs(node.right);
        if (ld > rd) return [ld + 1, ln];
        else if (rd > ld) return [rd + 1, rn];
        else return [ld + 1, node];
    }
    return dfs(root)[1];
}
