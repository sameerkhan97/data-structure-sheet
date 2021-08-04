/* Given a Binary Tree, print the diagonal traversal of the binary tree.Consider lines of slope -1 passing between nodes. 
   Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
Explanation:
Diagonal Traversal of binary tree : 
 8 10 14 3 6 7 13 1 4
*/

vector<int> diagonal(Node *root)
{
   vector<int> ans;
   if(!root) return ans;
   queue<Node *> q;
   q.push(root);
   while(!q.empty()){
       Node *c=q.front();
       q.pop();
       //queue will store left child of each node and printing the right child
       //this will give us diagonal traversal
       while(c!=NULL){
            if(c->left)     q.push(c->left);
            ans.push_back(c->data);
            c=c->right;
       }
    }
}