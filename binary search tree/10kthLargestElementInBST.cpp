/* Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification 
   in Binary Search Tree.
 
Example 1:
Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:
Input:
       9
        \ 
          10
K = 1
Output: 10   */

class Solution
{
    public:
    int kthLargest(Node *root, int k)
    {
        vector<int> arr;
        queue<Node *> q;
        q.push(root);
        //traversing the tree inorder
        while(!q.empty()){
            Node *temp=q.front();
            q.pop();
            arr.push_back(temp->data);
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        //sort the inorder array and returining the corresponding largest element
        sort(arr.begin(),arr.end());
        return arr[arr.size()-k];
    }
};