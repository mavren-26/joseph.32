
class Solution {
public:
    bool helper(TreeNode* node, long lower, long upper) {
        if (!node) return true;
        if (node->val <= lower || node->val >= upper) return false;
        return helper(node->left, lower, node->val) && helper(node->right, node->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
