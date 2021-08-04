/* Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Example 1:

Input:
       1
    /    \
   3      2
Output: 1 2
Example 2:

Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60  */


//refer to left veiw answer first
// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
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
          //traversig remaining nopdes of a lvl stored in queue 
          //and popping them out
          while(sz--){
               Node *c=q.front();
               q.pop();
               if(c->right)  q.push(c->right); 
               if(c->left)   q.push(c->left);    
          }
      }
      return ans;
    }
};