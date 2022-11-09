//Diameter is the longest path b/w any two nodes. Path doesnt need to pass through root
//TC:O(n)
//SC:O(n) worst case when tree is skwed
class Solution {
    int height(TreeNode* root,int &maxi)
    {
        if(root==NULL) return 0;
        int l=height(root->left,maxi);
        int r=height(root->right,maxi);
        maxi=max(maxi,l+r);
        return max(l,r)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        height(root,maxi);
        return maxi;
    }
};
