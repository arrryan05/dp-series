class Solution {
public:
    int depth(int &maxdepth,TreeNode* root)
    {
        if(root==NULL)return 0;
        int lh=depth(maxdepth,root->left);
        int rh=depth(maxdepth,root->right);
        maxdepth=max(maxdepth,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdepth=0;
        int ans=depth(maxdepth,root);
        return maxdepth;
    }
};