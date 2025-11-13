struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int res = 0;
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [ls, ln] = dfs(node->left);
        auto [rs, rn] = dfs(node->right);
        int sum = ls + rs + node->val;
        int num = ln + rn + 1;
        if (node->val == sum / num) res++;
        return {sum, num};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};
