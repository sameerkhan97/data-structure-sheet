/* Given a Binary Tree, find the In-Order Traversal of it.
Example 1:
Input:
       1
     /  \
    3    2
Output: 3 1 2

Example 2:
Input:
        10
     /      \ 
    20       30 
  /    \    /
 400    60  50
Output: 40 20 60 10 50 30
*/

//INORDER : = left->root->right

// Recursive function to perform inorder traversal on the tree
void inorder(Node* root)
{
    // return if the current node is empty
    if (root == nullptr) {
        return;
    }
 
    // Traverse the left subtree
    inorder(root->left);
 
    // Display the data part of the root (or current node)
    cout << root->data << " ";
 
    // Traverse the right subtree
    inorder(root->right);
}

//Iterative method
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        //taking all the left child nodes from root
        while(root){
            st.push(root);
            root=root->left;
        }
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            root=temp->right;
            //now taking deepest left child node of current node
            while(root){
                st.push(root);
                root=root->left;
            }
        }
        return ans;
    }
}; 