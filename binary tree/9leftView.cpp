/* Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
 The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /   \     / \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

*/
}//Function to return a list containing elements of left view of the binary tree.
//we will store all node of a level in a queue and sent first node in array
//and remaining nodes are pop() from queue
vector<int> leftView(Node *root)
{
   vector<int> ans;
   queue<Node *> q;
   if(!root) return ans;
   q.push(root);
   //doing level order traversal
   while(!q.empty()){
       int sz=q.size();
       //storing first node into array
       ans.push_back(q.front()->data);
       //traversig remaining nopdes of alvl stored in queue 
       //and popping them out
       while(sz--){
           Node *c=q.front();
           q.pop();
           if(c->left)   q.push(c->left);
           if(c->right)  q.push(c->right);    
       }
   }
   return ans;
}