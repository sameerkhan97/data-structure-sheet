/*Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Example 1:
Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7

Example 2:
Input:
     2
   /   \
  1     3
n1 = 1, n2 = 3
Output: 2
*/

//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
    //if the node isn't found return NULL 
        if(!root)
            return NULL;

        //when anyone one of the node is found return root 
        if(root->data==n1 or root->data==n2)
            return root;
        //search for in left-subtree
        Node* l=LCA(root->left,n1,n2);
        //seatch in right-subtree
        Node* r=LCA(root->right,n1,n2);
        //if both left and right subtree return anode then curr node is a LCA,return it
        if(l and r)
            return root;
        //of only one node is found in a subtree then returning only that node
        else if(l)
            return l;
        else
            return r;
}