/* Given a binary tree, find the Postorder Traversal of it.
For Example, the postorder traversal of the following tree is:
5 10 39 1

        1
     /     \
   10     39
  /
5


Example 1:

Input:
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19
Example 2:

Input:
          11
         /
       15
      /
     7
Output: 7 15 11

*/

void postorder(Node* root)
{
    // if the current node is empty
    if (root == nullptr) {
        return;
    }
 
    // Traverse the left subtree
    postorder(root->left);
 
    // Traverse the right subtree
    postorder(root->right);
 
    // Display the data part of the root (or current node)
    cout << root->data << " ";
}