/*Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree.
  The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Example 1:
Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2

Example 2:
Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 
40<=>20<=>60<=>10<=>30.

*/

class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void solve(Node* root,Node* &head,Node* &prev,int &f){
        if(!root) return;
        //inorder traversal
        solve(root->left,head,prev,f);
        //if f==0 then this is first node hence,just connecting it with head
        if(f==0){
            f=1;
            head=root;
            prev=root;
        }
        else{
            //prev nodee will point to this new node
            prev->right=root;
            //now new node's left pointer will point to previous node
            (prev->right)->left=prev;
            //pointing to new node as previous
            prev=prev->right;
        }
        solve(root->right,head,prev,f);
    }
    Node * bToDLL(Node *root)
    {
        Node* head=NULL;
        Node* prev=NULL;
        int f=0;    //f-will check for 1st node to join with head
        solve(root,head,prev,f);
        return head;
    }
};