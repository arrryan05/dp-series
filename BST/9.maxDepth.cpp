class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
          return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1)  return -1;
        return max(leftDepth, rightDepth)+1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)  return true;
	    if (maxDepth(root) == -1)  return false;
		return true;
    }
};