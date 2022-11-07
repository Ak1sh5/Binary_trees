//A structure is a user-defined data type in C/C++.
//A structure creates a data type that can be used to group items of possibly different types into a single type. 
struct node{
 int data;
  struct node * left;
  struct node *right;
  
  node(int val)
  {
    data=val;
    left=right=NULL;
  }
};

int main()
{
   struct node *root=new node(1);
  root->left=new node(2);
  root->right =new node(3);
  root->left->right=new node(5);
  
}
