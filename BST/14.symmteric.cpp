class Solution {
public:
    bool check(TreeNode*first, TreeNode* second) {
        if(!first and !second)
            return true;
        if(!first or !second) {
            return false;
        }
        
        if(first->val != second->val) return false;
        
        return check(first->left, second->right) and check(first->right, second->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return check(root->left, root->right);
    }
};