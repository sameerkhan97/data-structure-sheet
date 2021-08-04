/* Given a binary tree, find its level order traversal. Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2
Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N



*/

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        vector<int> res;
        if(node==NULL)
            return res;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* temp=q.front();
            res.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            q.pop();
        }
        return res;
    }
};