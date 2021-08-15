
/*Given a Binary Tree with all unique values and two nodes value n1 and n2. The task is to find the lowest common ancestor of the
  given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them is present. 

Example 1:
Input:
n1 = 2 , n2 =  3
     1
   /  \
  2    3
Output: 1
Explanation: LCA of 2 and 3 is 1.

Example 2:
Input:
n1 = 3 , n2 = 4
         5
        /
       2
     /  \
    3    4
Output: 2
Explanation: LCA of 3 and 4 is 2.  */

Node* lca(Node* root ,int n1 ,int n2 )
{
        //if the node isn't found return NULL 
        if(!root)
            return NULL;

        //when anyone one of the node is found return root 
        if(root->data==n1 or root->data==n2)
            return root;
        //search for in left-subtree
        Node* l=lca(root->left,n1,n2);
        //seatch in right-subtree
        Node* r=lca(root->right,n1,n2);
        //if both left and right subtree return anode then curr node is a LCA,return it
        if(l and r)
            return root;
        //of only one node is found in a subtree then returning only that node
        else if(l)
            return l;
        else
            return r;
}