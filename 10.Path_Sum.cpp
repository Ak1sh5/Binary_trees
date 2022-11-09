//TC:O(n) SC:O(n)
class Solution {
public:
    void check(TreeNode* root, int targetSum,bool &isPath){
        if(root==NULL)return;
        targetSum-=root->val;
        if(root->left==NULL &&root->right ==NULL){
            if(targetSum==0)isPath=true;
        }
        check(root->left,targetSum,isPath);
        check(root->right,targetSum,isPath);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool isPath=false;
        check(root,targetSum,isPath);
        return isPath;
        
    }
};

//or
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // return false if the root is nullptr
        if(!root) return false;
        // if it reaches to the end and the val is equal to targetSum, return true
        if(!root->left && !root->right && root->val == targetSum) return true;
        // otherwise, we traverse left node and right node with the new targetSum `targetSum - root.val`
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};
