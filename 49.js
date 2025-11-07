

var isValidBST = function(root) {
    function helper(node, lower = -Infinity, upper = Infinity) {
        if (!node) return true;
        if (node.val <= lower || node.val >= upper) return false;
        return helper(node.left, lower, node.val) && helper(node.right, node.val, upper);
    }
    return helper(root);
};
