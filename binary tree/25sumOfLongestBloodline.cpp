/* Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on 
   the longest path from root to leaf node.If two or more paths compete for the longest path, then the path having maximum sum of nodes
   is being considered.

Example 1:

Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13
Example 2:

Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 11

*/

class Solution
{
public:
    vector<int> solve(Node *root){
        //base condition
        //if this is the leaf node return empty vector
        if(!root){
            vector<int> temp={};
            return temp;
        }
        //left to store nodes in left subtree of a node
        vector<int> left=solve(root->left);
        //right to store nodes in right subtree of a node
        vector<int> right=solve(root->right);
        //checking longer between left & right subtree of a node
        //the current node will be pushed with longer subtree & path will be returned
        if(left.size()>right.size()){
            left.push_back(root->data);
            return left;
        }
        else{
            right.push_back(root->data);
            return right;
        }
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //calling solve to get the longest path array
        //array will contain all the node in path
        vector<int> ans=solve(root);
        int sum=0;
        //finding sum of all nodes
        for(auto x:ans)
            sum+=x;
        return sum;
    }
};