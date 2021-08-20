/*Given a Binary Tree, write a function to populate next pointer for all nodes. 
  The next pointer for every node should be set to point to inorder successor.

Example 1:
Input:
           10
       /  \
      8    12
     /
    3
Output: 3->8 8->10 10->12 12->-1
Explanation: The inorder of the above tree is : 3 8 10 12. So the next pointer of node 3 is pointing to 8 , next pointer of 8 is pointing
to 10 and so on.And next pointer of 12 is pointing to -1 as there is no inorder successor of 12.

Example 2:
Input:
           1
      /   \
     2     3
Output: 2->1 1->3 3->-1 
*/

class Solution
{
public:
    //using inorder traversal the function will point every node's next pointer
    //to the inorder
    void solve(Node* root,Node* &prev){
        if(!root)   return;
        solve(root->left,prev);
        //if we havent reached the last left-most node till then prev will be null
        if(prev!=NULL){
            prev->next=root;
        }
        prev=root;
        solve(root->right,prev);
    }
    void populateNext(Node *root)
    {
        Node* prev=NULL;
        solve(root,prev);
    }
};