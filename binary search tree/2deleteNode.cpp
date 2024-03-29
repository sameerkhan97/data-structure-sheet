/*Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference
 (possibly updated) of the BST. 
 
Basically, the deletion can be divided into two stages:
i] Search for a node to remove.  ii] If the node is found, delete the node.

Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.One valid answer is [5,4,6,2,null,null,7], 
shown in the above BST.Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
Output: []
*/

class Solution {
public:
    //func to find inorder successor
    TreeNode* insucc(TreeNode* node){
        TreeNode* p=node->right;
        while(p->left)  p=p->left;
        return p;
    }
    void swap(int &a,int &b){
        int t=a;
        a=b;
        b=t;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)  return NULL;
        if(root->val<key)  root->right=deleteNode(root->right,key);
        else if(root->val>key) root->left=deleteNode(root->left,key);
        else{
            //if node have only 1 child then appending it's only child in node's position
            //if node have no child then null is appended to it's position
            if(!root->right){
               TreeNode* temp=root->left;
                delete(root);
                return temp;               
            }
            else if(!root->left){
                TreeNode* temp=root->right;
                delete(root);
                return temp;
            }
            //if node have both child
            //then swapping node's value with it's inorder successor
            //then moving ahead to delete the successor node
            
            else{
                TreeNode* temp=insucc(root);
                swap(root->val,temp->val);
                root->right=deleteNode(root->right,key);               
            }
        }
        return root;
    }
};