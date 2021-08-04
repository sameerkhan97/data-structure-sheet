/*Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5+-

*/

class Solution{
    public:
    int idx;
    unordered_map<int,int> m;
    
    Node* solve(int pre[],int in[],int lb,int ub){
        if(lb>ub)   return NULL;
        Node* res=new Node(pre[idx++]);
        if(lb==ub)  return res;
        int mid=m[res->data];
        res->left=solve(pre,in,lb,mid-1);
        res->right=solve(pre,in,mid+1,ub);
        return res;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        idx=0;
        m.clear();
        for(int i=0;i<n;i++){
            m[in[i]]=i;
        }
        Node* root=solve(pre,in,0,n-1);
        return root;
    }
};