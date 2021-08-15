/*Given a binary tree and two node values your task is to find the minimum distance between them.
Example 1:
Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.Being at node 2, we need to take two steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2. 
*/

int findDist(Node* root, int a, int b) {
    //finding LCA of both the nodes
    Node* LCA=lca(root,a,b);
    //now finding distance of each node with lca node
    int x=solve(LCA,a);
    int y=solve(LCA,b);
    return x+y-2;
}
Node* lca(Node* root ,int n1 ,int n2 )
{
    if(!root)
        return NULL;
    if(root->data==n1 or root->data==n2)
        return root;
    Node* l=lca(root->left,n1,n2);
    Node* r=lca(root->right,n1,n2);
    if(l and r)
        return root;
    else if(l)
        return l;
    else
        return r;
}
int solve(Node* root,int a){
    if(!root)   return 0;
    //if this node matches then return 1
    if(root->data==a)
        return 1;
    //l to find node in left subtree
    int l=solve(root->left,a);
    //r to find node in right subtree
    int r=solve(root->right,a);
    
    //if  node is found in left or right subtree
    //then it will return 1 else 0
    if(!l && !r)
        return 0;
    //returning total number of nodes from curr node to searching nide
    else
        return l+r+1;
}