/*Given a BST and an integer K. Find the Kth Smallest element in the BST. 
Example 1:
Input:
      2
    /   \
   1     3
K = 2
Output: 2

Example 2:
Input:
        2
      /  \
     1    3
K = 5
Output: -1

Your Task: You don't need to read input or print anything. Your task is to complete the function KthSmallestElement() which takes the root
 of the BST and integer K as inputs and return the Kth smallest element in the BST, if no such element exists return -1.
*/ 

class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    int KthSmallestElement(Node *root, int K)
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
        //sort the inorder array and returning the corresponding smallest element
        sort(arr.begin(),arr.end());
        if(K>arr.size())    return -1;
        return arr[K-1];
    }
};