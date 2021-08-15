/*Given a binary tree in which nodes are numbered from 1 to n. Given a node and a positive integer K. We have to print the Kth ancestor of the
 given node in the binary tree. If there does not exist any such ancestor then print -1.
For example in the below given binary tree, the 2nd ancestor of 5 is 1. 3rd ancestor of node 5 will be -1. 
         1
      /     \
     2       3
   /   \ 
  4     5

*/


Node* temp = NULL;
 
// recursive function to calculate Kth ancestor
Node* kthAncestorDFS(Node *root, int node , int &k)
{  
    // Base case
    if (!root)
        return NULL;
     
    if (root->data == node || (temp =  kthAncestorDFS(root->left,node,k)) || (temp =  kthAncestorDFS(root->right,node,k)))
    {  
        if (k > 0)       
            k--; 
        else if (k == 0){
            // print the kth ancestor
            cout<<"Kth ancestor is: "<<root->data;
             
            // return NULL to stop further backtracking
            return NULL;
        }
        // return current node to previous call
        return root;
    }
}