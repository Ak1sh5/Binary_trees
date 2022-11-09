//TC:O(n)
//SC:O(n)
class Solution {
    int f(TreeNode*root,int &maxi)
    {
        if(root==NULL) return 0;
        int l=max(0,f(root->left,maxi));
        int r=max(0,f(root->right,maxi));
        maxi=max(maxi,root->val+l+r);
        return max(l,r)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        f(root,maxi);
        return maxi;
    }
};
