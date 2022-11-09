
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>temp;
            for(int i=0;i<size;i++)
            {
                TreeNode* t =q.front();
                q.pop();
                if(t->left!=NULL)q.push(t->left);
                if(t->right!=NULL)q.push(t->right);
                temp.push_back(t->val);
                
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
