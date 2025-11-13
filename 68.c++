pair<int, TreeNode*> dfs(TreeNode* node) {
    if (!node) return {0, NULL};
    auto [ld, ln] = dfs(node->left);
    auto [rd, rn] = dfs(node->right);
    if (ld > rd) return {ld + 1, ln};
    else if (rd > ld) return {rd + 1, rn};
    else return {ld + 1, node};
}

TreeNode* lcaDeepestLeaves(TreeNode* root) {
    return dfs(root).second;
}
