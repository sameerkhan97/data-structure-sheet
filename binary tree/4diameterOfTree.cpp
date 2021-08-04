/* Given a Binary Tree, find diameter of it.The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree.
   The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded 
   (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).
*/ 
class Solution
{
    public:
    int ma;
    int func(Node* root){
        if(!root)
            return 0;
        int x=func(root->left);
        int y=func(root->right);
        ma=max(ma,x+y+1);
        return (max(x,y)+1);
    }
    
    int diameter(Node* root){
        ma=INT_MIN;
        int x=func(root);
        return ma;
    }
    int max(int a,int b){
        if(a>b)
            return a;
        return b;
    }

};