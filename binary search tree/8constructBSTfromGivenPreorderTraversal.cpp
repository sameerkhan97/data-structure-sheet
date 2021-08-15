/*Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), 
 construct the tree and return its root.
It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, 
and any descendant of Node.right has a value strictly greater than Node.val.
A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right. 

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be the root of the following tree.

     10
   /   \
  5     40
 /  \      \
1    7      50
*/

class Solution {
public:
    //
    TreeNode* buildBST(TreeNode* &root,int ele){
        //create node when at leaf
        if(!root)
            return root=new TreeNode(ele);
        //adding node to left subtree
        if(root->val>ele)
            root->left=buildBST(root->left,ele);
        //adding node to right subtree
        else 
            root->right=buildBST(root->right,ele);
        //returning root node
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        //take elements from array one by one and according to root's value
        //making it into left or right subtree
        for(auto x:preorder){
            buildBST(root,x);
        }
        return root;
    }
};