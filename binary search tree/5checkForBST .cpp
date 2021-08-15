/*Given a binary tree. Check whether it is a BST or not.    Note: We are considering that BSTs can not contain duplicate Nodes.

Example 1:
Input:
    2
 /    \
1      3
Output: 1 
Explanation: The left subtree of root node contains node with key lesser than the root node’s key and the right subtree of root node 
contains node with key greater than the root node’s key.Hence, the tree is a BST.

Example 2:
Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 
Explanation: Since the node with value 7 has right subtree nodes with keys less than 7, this is not a BST.
*/

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    //flag to check for BST
    int f=1;
    //here we will be doing inorder traversal and after reaching the lowest node 
    //we will compare all nodes with there previos(child) node as per the condition
    void checkBST(Node* root,Node* &prev){
        if(!root)   return;
        checkBST(root->left,prev);
        if(prev!=NULL && prev->data>=root->data){
            f=0;
            return ;
        }
        prev=root;
        checkBST(root->right,prev);
    }
    
    bool isBST(Node* root) 
    {
        f=1;
        Node* prev=NULL;
        checkBST(root,prev);
        return f;
    }
};