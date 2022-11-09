//For both SC and TC is O(n)

//Level Order Traversal Approach 

int maxDepth(TreeNode* root) {
        int depth = 0;
        
        if (root == NULL) return depth;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp -> left != NULL) q.push(temp -> left);
                if (temp -> right != NULL) q.push(temp -> right);
            }
        }
        
        return depth;
    }
//Recursive apporach
int maxdepth(TreeNode* root)
{
  if(root==NULL) return 0;
  int l=maxdepth(root->left);
  int r=maxdepth(root->right);
  return max(l,r)+1;
}
