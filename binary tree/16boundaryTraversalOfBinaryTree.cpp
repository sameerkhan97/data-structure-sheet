/* Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel 
                     preferring the left subtree over the right subtree. 

Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could 
                     reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it
                     was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:
Input:
        1
      /   \
     2     3    
   
Output: 1 2 3

Example 2:
Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22    */

class Solution {
public:
    vector<int> ans;
    void leftNode(Node *root){
        if(!root)   return;
        if(root->left){
            ans.push_back(root->data);
            leftNode(root->left);
        }
        else if(root->right){
            ans.push_back(root->data);
            leftNode(root->right);
        }
    }
    void leafNode(Node *root){
        if(!root) return ;
        leafNode(root->left);
        //only leaf nodes will be stored in vector
        if(!root->left && !root->right)
            ans.push_back(root->data);
        leafNode(root->right);
    }
    void rightNode(Node *root){
        if(!root)   return; 
        if(root->right){
            //traversing the tree first recursively snf=d then storing data in vector
            //to tht it will be stored in reverse order
            rightNode(root->right);
            ans.push_back(root->data);
        }
        else if(root->left){
            rightNode(root->left);
            ans.push_back(root->data);
        }
    }
    vector <int> printBoundary(Node *root)
    {
        ans.push_back(root->data);
        //to print left boundary
        leftNode(root->left);
        //to print leaf nodes
        leafNode(root);
        //to print right boudary
        rightNode(root->right);
        return ans;
    }
};