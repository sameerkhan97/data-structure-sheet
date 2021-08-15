/*
 Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), 
 that returns the count of all pairs from both the BSTs whose sum is equal to x.
 Example 1:
Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8

BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18

x = 16
Output: 3
Explanation: The pairs are: (5, 11), (6, 10) and (8, 8)
*/

//Brute Force TC :- O(n+m) ,SC : - O(m)
class Solution
{0
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        unordered_map<int,int> m;
        queue<Node*> q;
        q.push(root2);
        //mapping all nodes of bst 2 
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            m[temp->data]=1;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
        q.push(root1);
        int count=0;
        
        //now checking is the diff. of x and bst1 node already 
        //present in bst2 if found then it is pair=x
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(m[x-(temp->data)])
                count++;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return count;
    }
};


//better solution,w/o extra space ,TC :- O(n+h)
//instead of mapping every element in bst2 ,
//we will directly search required element in bst which will cost us O(h) TC
class Solution
{
public:
    Node* search(Node* root,int a){
        if(root==NULL || root->data==a)
            return root;
        if(root->data>a)
            return search(root->left,a);
        return search(root->right,a);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        queue<Node*> q;
        q.push(root1);
        int count=0;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(search(root2,x-(temp->data)))
                count++;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return count;
    }
};