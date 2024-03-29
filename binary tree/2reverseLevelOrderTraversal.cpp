/* Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

Example 1:

Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
Example 2:

Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10

*/

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> res;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        res.push_back(temp->data);
        
        if(temp->right)
            q.push(temp->right);
        
        if(temp->left)
            q.push(temp->left);
        
        q.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}