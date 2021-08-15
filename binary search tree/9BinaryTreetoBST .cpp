/* Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.

Example 1:
Input:
      1
    /   \
   2     3
Output: 1 2 3

Example 2:
Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1

*/

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void treeIn(Node *root,vector<int> &arr){
        if(!root)   return;
        treeIn(root->left,arr);
        arr.push_back(root->data);
        treeIn(root->right,arr);
    }
    void bstIn(Node *root,vector<int> arr,int &i){
        if(!root)  return ;
        bstIn(root->left,arr,i);
        root->data=arr[i];
        i++;
        bstIn(root->right,arr,i);
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> arr;
        //finding in order traversal of gievne binary tree
        treeIn(root,arr);
        //now sorting the inorder traversal array of binary tree
        //it will result in inorder traversal array of binary search tree
        sort(arr.begin(),arr.end());
        int i=0;
        //one by traversing each node of tree inorder-ly 
        //and assigninng it corresponding value from vector
        bstIn(root,arr,i);
        return root;
    }
};