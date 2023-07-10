class Solution {
public:
    vector<int> v;
    void pre(TreeNode* root)
    {
        if(root==NULL) return;
        v.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return v;
    }
};