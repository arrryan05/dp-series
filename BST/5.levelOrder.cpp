class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n=q.size();
            for (int i=0;i<n;i++){
			TreeNode* currNode = q.front();

			level.push_back(q.front()->val);
			q.pop();

			if (currNode->left)
				q.push(currNode->left);
			if (currNode->right)
				q.push(currNode->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};