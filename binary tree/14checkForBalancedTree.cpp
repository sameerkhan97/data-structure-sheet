/* Given a binary tree, find if it is height balanced or not. 
   A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5
 
Example 1:
Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height of left subtree and right subtree is 2, which is greater than 1. Hence unbalanced

Example 2:
Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 
*/

//Function to check whether a binary tree is balanced or not.
bool flag=true;
int solve(Node* root){
    if(!root) return 0;
    int left=solve(root->left);
    int right=solve(root->right);
    //if the current nodes height dont show balanced condition 
    //then mrk flg as flase  
    if(abs(left-right)>1)    flag=false;
    if(left>right)  
        return left+1;
    else
        return right+1;
}
bool isBalanced(Node *node)
{
    flag=true;
    //solve method will calculate height of each node 
    //and check if it shows blanced tree condition
    solve(node);
    return flag;
}