/* Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes 
   visible when the tree is viewed from the top. For the given below tree
       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:
Input:
      1
   /    \
  2      3
Output: 2 1 3

Example 2:
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        //map to mark if the node if already visited
        map<int,int> m;
        //queu will store all nodes and their heights
        queue<pair<Node *,int>> q;
        if(!root)   return ans;
        q.push({root,0});
        while(!q.empty()){
            //popping first Node from queue
            Node *c=q.front().first;
            int h=q.front().second;
            q.pop();
            //if current node isnt visited ,mark it visited 
            //and store its data in map
            if(!m[h])   m[h]=c->data;
            if(c->left) q.push({c->left,h-1});
            if(c->right) q.push({c->right,h+1});
        }
        //storing data into vector
        for (auto x:m)
            ans.push_back(x.second);
         return ans;
    }
    
};