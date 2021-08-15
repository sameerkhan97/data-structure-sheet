/*Given a binary tree, task is to find subtree with maximum sum in tree.
Examples: 
 

Input :       1
            /   \
           2      3
          / \    / \
         4   5  6   7
Output : 28
As all the tree elements are positive,the largest subtree sum is equal to sum of all tree elements.

Input :       1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
Output : 7
Subtree with largest sum is :  -2
                             /  \ 
                            4    5
Also, entire tree sum is also 7.
*/


int ans;

int solve(Node *root){
    if(!root)
        return 0;

    int currSum=root->dat+solve(root->left)+solve(root->right);
    ans=max(ans,currSum);
    return currSum;
}

int findLargestSubtreeSum(Node* root){
    ans=INT_MIN;
    solve(Node *root);
    return ans;
}