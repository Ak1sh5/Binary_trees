//Preorder (node,left,right)
//Postorder (left,right,node)
//Inorder   (left,node,right)

//TC:O(n)  Reason: We are traversing N nodes and every node is visited exactly once.
//SC: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).

//Recursion way
#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void preOrderTrav(node * curr, vector < int > & preOrder) {
  if (curr == NULL)
    return;

  preOrder.push_back(curr -> data);
  preOrderTrav(curr -> left, preOrder);
  preOrderTrav(curr -> right, preOrder);
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(8);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> right = newNode(10);

  vector < int > preOrder;
  preOrderTrav(root, preOrder);

  cout << "The preOrder Traversal is : ";
  for (int i = 0; i < preOrder.size(); i++) {
    cout << preOrder[i] << " ";
  }
  return 0;
}
//Iterative way
//same TC and SC, Reason of SC: In the worst case, (a tree with every node having a single right child and left-subtree)
//Preorder iterative
vector < int > preOrderTrav(node * curr) {
  vector < int > preOrder;
  if (curr == NULL)
    return preOrder;

  stack < node * > s;
  s.push(curr);

  while (!s.empty()) {
    node * topNode = s.top();
    preOrder.push_back(topNode -> data);
    s.pop();
    if (topNode -> right != NULL)
      s.push(topNode -> right);
    if (topNode -> left != NULL)
      s.push(topNode -> left);
  }
  return preOrder;

}

//Indorder iterative
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> st;
        while(true)
        {
            if(root)
            {

                st.push(root);
                root=root->left;
                
            }
            else
            {
                if(st.empty())break;
                root=st.top();
                st.pop();
                answer.push_back(root->val);
                root=root->right;
                
            }
        }
return answer;
    }
};

//Postorder iterative using two stacks 
//SC: O(2n)
class Solution {
   
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>answer;
        if(root==NULL) return answer;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        while(!st1.empty())
        {
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left) st1.push(root->left);
            if(root->right) st1.push(root->right);
            
        }
        while(!st2.empty())
        {
            answer.push_back(st2.top()->val);
            st2.pop();
        }
        return answer;
       
    }
};

//Postorder iterative using one stack
//TC:O(2n)
//SC:O(n)

vector < int > postOrderTrav(node * cur) {

  vector < int > postOrder;
  if (cur == NULL) return postOrder;

  stack < node * > st;
  while (cur != NULL || !st.empty()) {

    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    } else {
      node * temp = st.top() -> right;
      if (temp == NULL) {
        temp = st.top();
        st.pop();
        postOrder.push_back(temp -> data);
        while (!st.empty() && temp == st.top() -> right) {
          temp = st.top();
          st.pop();
          postOrder.push_back(temp -> data);
        }
      } else cur = temp;
    }
  }
  return postOrder;

}


