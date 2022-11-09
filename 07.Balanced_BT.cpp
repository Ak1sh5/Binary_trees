//Method-1 TC:O(n*n)
class Solution {
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int l= height(root->left);
        int r= height(root->right);
        return 1+max(l,r);
        
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int left=height(root->left);
        int right=height(root->right);
        if(abs(left-right)>1) return false;
        bool s=isBalanced(root->left);
        bool t=isBalanced(root->right);
        if(!s||!t)return false;
        return true;
        
    }
};

//Method-2 TC:O(n) SC:O(n) in case of skwed trees
class Solution {
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int l= height(root->left);
        int r= height(root->right);
        if(l==-1||r==-1||abs(l-r)>1) return -1;
        return 1+max(l,r);
        
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
       if(height(root)==-1)return false;
        return true;
        
    }
};
