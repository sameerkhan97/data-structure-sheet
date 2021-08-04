/* Given a Binary Tree, check if all leaves are at same level or not.

Example 1:
Input: 
            1
          /   \
         2     3

Output: 1
Explanation:  Leaves 2 and 3 are at same level.

Example 2:
Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0
Explanation:  Leaves 10, 15 and 30 are not at same level.
*/

class Solution{
  public:
    /*You are required to complete this method*/
    int ans=1;
    void solve(Node *root,int h,int &ma)
    {
        if(!root)
            return;
        //if previouys nodes deny the level; condition then no need to go further
        if(ans==0)
            return;
        //when arrive at leaf node
        if(!root->right && !root->left){
            //if it is the first leaf node we encounter
            //store its depth in h
            if(ma==-1)
                ma=h;
            //if the leaf nodes depth is diffeent from previous leaf 
            //node's depth then   retun flse
            else if(ma!=h)
                    ans=0;
            return;
        }
        //traverse in depth of tree
        solve(root->left,h+1,ma);
        solve(root->right,h+1,ma);
    }
    bool check(Node *root)
    {
        int ma=-1;
        int h=0;
        solve(root,h,ma);
        return ans;
    }
};