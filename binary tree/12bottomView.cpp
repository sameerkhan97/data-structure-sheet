/*Given a binary tree, print the bottom view from left to right.
  A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. 
For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.

*/

//Function to return a list containing the bottom view of the given tree.
vector <int> bottomView(Node *root)
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
            //save the current node data in map with its position
            //all nodes with same positions will be over written by last node
            m[h]=c->data;
            if(c->left) q.push({c->left,h-1});
            if(c->right) q.push({c->right,h+1});
        }
        //storing data into vector
        for (auto x:m)
            ans.push_back(x.second);
        return ans;
}